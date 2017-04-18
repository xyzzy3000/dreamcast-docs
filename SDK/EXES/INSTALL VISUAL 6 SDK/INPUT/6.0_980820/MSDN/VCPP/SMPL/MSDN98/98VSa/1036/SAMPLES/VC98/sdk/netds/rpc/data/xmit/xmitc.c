/****************************************************************************
                   Microsoft RPC Version 2.0
           Copyright Microsoft Corp. 1992, 1993, 1994- 1996
                       xmit Example

    FILE:       xmitc.c

    USAGE:      xmitc  -n network_address
                       -p protocol_sequence
                       -e endpoint
                       -o options
                       -c count of elements in linked list
                       -v value of first element in linked list
                       -d delta between values in linked list

    PURPOSE:    Client side of RPC distributed application.
                This sample demonstrates the transmit_as example.
                A doubly-linked list is transmitted over the network
                as a sized array.

    RELATED:    xmits.c - server main
                xmitp.c - remote procedures
                xmitu.c - utility procedures

    FUNCTIONS:  main() - bind to server and call remote procedure

    COMMENTS:   This sample program generates a linked list to
                demonstrate how a list with aliasing can be transmitted
                using the transmit_as attribute as a sized array.
                The pointers are rebuilt on the server side.

                The [transmit_as] attribute (used in the typedef of
                DOUBLE_LINK_TYPE in the file XMIT.IDL) requires the
                four user-supplied functions whose names start with
                the name of the presented type, DOUBLE_LINK_TYPE.

                The [in, out] attributes applied to remote procedure
                parameters require the two user-supplied functions
                midl_user_allocate and midl_user_free.

                The other functions are utilities that are used to
                build or display the data structures.


****************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "xmit.h"     // header file generated by MIDL compiler
#include "xmitu.h"    // utility function prototypes

#define PURPOSE \
"This Microsoft RPC Version 2.0 sample program demonstrates\n\
the use of the [transmit_as] attribute. For more information\n\
about the attributes and the RPC API functions, see the\n\
RPC programming guide and reference.\n\n"

#define MAX_ELEMENTS 50

void Usage(char * pszProgramName)
{
    fprintf(stderr, "%s", PURPOSE);
    fprintf(stderr, "Usage:  %s\n", pszProgramName);
    fprintf(stderr, " -p protocol_sequence\n");
    fprintf(stderr, " -n network_address\n");
    fprintf(stderr, " -e endpoint\n");
    fprintf(stderr, " -o options\n");
    fprintf(stderr, " -c count_of_elements\n");
    fprintf(stderr, " -v value\n");
    fprintf(stderr, " -d delta\n");
    exit(1);
}

void _CRTAPI1 main(int argc, char **argv)
{
    RPC_STATUS status;
    unsigned char * pszUuid             = NULL;
    unsigned char * pszProtocolSequence = "ncacn_np";
    unsigned char * pszNetworkAddress   = NULL;
    unsigned char * pszEndpoint         = "\\pipe\\xmit";
    unsigned char * pszOptions          = NULL;
    unsigned char * pszStringBinding    = NULL;
    int i;
    int cElements = 10;
    short sValue = 100;
    short sDelta = 10;

    DOUBLE_LINK_TYPE *pFirst, *pCurrent;

    /* allow the user to override settings with command line switches */
    for (i = 1; i < argc; i++) {
        if ((*argv[i] == '-') || (*argv[i] == '/')) {
            switch (tolower(*(argv[i]+1))) {
            case 'p':  // protocol sequence
                pszProtocolSequence = argv[++i];
                break;
            case 'n':  // network address
                pszNetworkAddress = argv[++i];
                break;
            case 'e':
                pszEndpoint = argv[++i];
                break;
            case 'o':
                pszOptions = argv[++i];
                break;
            case 'c':
                cElements = atoi(argv[++i]);
                if (cElements > MAX_ELEMENTS)
                    cElements = MAX_ELEMENTS;
                break;
            case 'v':
                sValue = (short)atoi(argv[++i]);
                break;
            case 'd':
                sDelta = (short)atoi(argv[++i]);
                break;
            case 'h':
            case '?':
            default:
                Usage(argv[0]);
            }
        }
        else
            Usage(argv[0]);
    }

    /* initialize a list with a number of elements */
    pFirst = InsertNewNode(sValue, NULL);
    pCurrent = pFirst;   // assign some values to the list nodes
    sValue += sDelta;    // make them different values

    for (i = 1; i < cElements; i++) {
        pCurrent = InsertNewNode(sValue, pCurrent);
        sValue += sDelta;
    }
    ListWalkProc(pFirst);

    /* Use a convenience function to concatenate the elements of the string */
    /* binding into the syntax needed by RpcBindingFromStringBinding.       */
    status = RpcStringBindingCompose(pszUuid,
                                     pszProtocolSequence,
                                     pszNetworkAddress,
                                     pszEndpoint,
                                     pszOptions,
                                     &pszStringBinding);
    printf("RpcStringBindingCompose returned 0x%x\n", status);
    printf("pszStringBinding = %s\n", pszStringBinding);
    if (status) {
        exit(status);
    }

    /* Set the binding handle that will be used to bind to the server. */
    status = RpcBindingFromStringBinding(pszStringBinding,
                                         &hXmit);
    printf("RpcBindingFromStringBinding returned 0x%x\n", status);
    if (status) {
        exit(status);
    }

    RpcTryExcept {
        printf("Calling the remote procedure 'ModifyListProc'\n");
        ModifyListProc(pFirst);  // call the remote procedure

        printf("Calling the remote procedure 'Shutdown'\n");
        Shutdown();  // shut down the server side
    }
    RpcExcept(1) {
        printf("Runtime reported exception %ld\n", RpcExceptionCode() );
    }
    RpcEndExcept

    printf("After ModifyListProc, the list appears as follows:\n");
    ListWalkProc(pFirst);  // call the utility that displays the list

    /* The calls to the remote procedures are complete.            */
    /* Free the string and the binding handle using RPC API calls. */
    status = RpcStringFree(&pszStringBinding);
    printf("RpcStringFree returned 0x%x\n", status);
    if (status) {
        exit(status);
    }

    status = RpcBindingFree(&hXmit);
    printf("RpcBindingFree returned 0x%x\n", status);
    if (status) {
        exit(status);
    }

    exit(0);

}  // end main()

/* end file xmitc.c */