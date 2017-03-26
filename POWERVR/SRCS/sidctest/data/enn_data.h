/* Surface data - Blender Export - dcexport.py */

#ifndef __ENN_DATA_H
#define __ENN_DATA_H

/* Vertices */
float enn_coords[][3] = {
{-0.000634492025711, -0.888226985931, 0.000177181689651},
{-1.41421341896, 0.00103744084481, -1.28522515297e-07},
{0.00063443853287, 0.888226985931, 0.000177020061528},
{1.41421318054, -0.00103785144165, 1.28522515297e-07},
{-0.706587910652, 0.707625210285, 0.000176970890607},
{-0.707625329494, -0.706587851048, 0.000177100882865},
{0.706587731838, -0.707625448704, 0.00017723084602},
{0.70762526989, 0.706587731838, 0.000177100882865},
{-2.67370410256e-08, 2.39491484422e-08, 0.000177100882865},
{-4.52731114819e-07, -3.75081208404e-06, 1.24578678608},
{0.707624971867, 0.706584811211, 1.18238639832},
{0.706587433815, -0.707628369331, 1.18238651752},
{-0.707625746727, -0.706590771675, 1.18238639832},
{-0.70658826828, 0.707622349262, 1.18238627911},
{1.41421306133, -0.00103797751945, 0.989245772362},
{0.000634064839687, 0.888224124908, 1.18317830563},
{-1.41421353817, 0.00103727262467, 0.989245474339},
{-0.000634865718894, -0.888229906559, 1.18317842484},
{0.707625389099, 0.706587612629, -1.0115121603},
{0.706587851048, -0.707625567913, -1.01151204109},
{1.41421329975, -0.00103794271126, -1.01151204109},
{-0.70762526989, -0.706587970257, -1.0115121603},
{-0.706587791443, 0.707625150681, -1.01151227951},
{-1.41421329975, 0.00103734945878, -1.01151227951},
};

/* Faces */
int enn_face_idx[] = {
4, 8, 5, -1,
8, 7, 6, -1,
0, 8, 6, -1,
2, 7, 8, -1,
0, 5, 8, -1,
2, 8, 4, -1,
13, 12, 9, -1,
9, 11, 10, -1,
17, 11, 9, -1,
14, 10, 11, -1,
15, 9, 10, -1,
16, 12, 13, -1,
17, 9, 12, -1,
15, 13, 9, -1,
20, 19, 18, -1,
23, 22, 21, -1,
4, 15, 2, -1,
4, 13, 15, -1,
0, 12, 5, -1,
0, 17, 12, -1,
1, 13, 4, -1,
1, 16, 13, -1,
5, 16, 1, -1,
5, 12, 16, -1,
2, 10, 7, -1,
2, 15, 10, -1,
3, 11, 6, -1,
3, 14, 11, -1,
7, 14, 3, -1,
7, 10, 14, -1,
17, 0, 6, -1,
6, 11, 17, -1,
6, 20, 3, -1,
6, 19, 20, -1,
7, 19, 6, -1,
7, 18, 19, -1,
3, 18, 7, -1,
3, 20, 18, -1,
4, 23, 1, -1,
4, 22, 23, -1,
5, 22, 4, -1,
5, 21, 22, -1,
1, 21, 5, -1,
1, 23, 21, -1,
};

/* Texture Coords per vertex per face */
float enn_uv[][2] = {
0.7421875, 0.6484375,
0.4921875, 0.3671875,
0.7421875, 0.09375,
0.5, 0.5,
0.4921875, 0.3671875,
0.25, 0.6484375,
0.25, 0.09375,
0.5, 0.5,
0.4921875, 0.015625,
0.4921875, 0.3671875,
0.25, 0.09375,
0.5, 0.5,
0.4921875, 0.71875,
0.25, 0.6484375,
0.4921875, 0.3671875,
0.5, 0.5,
0.4921875, 0.015625,
0.7421875, 0.09375,
0.4921875, 0.3671875,
0.5, 0.5,
0.4921875, 0.71875,
0.4921875, 0.3671875,
0.7421875, 0.6484375,
0.5, 0.5,
0.25, 0.6484375,
0.25, 0.1484375,
0.5, 0.3984375,
0.5, 0.5,
0.5, 0.3984375,
0.75, 0.1484375,
0.75, 0.6484375,
0.5, 0.5,
0.5, 0.078125,
0.75, 0.1484375,
0.5, 0.3984375,
0.5, 0.5,
0.9921875, 0.3984375,
0.75, 0.6484375,
0.75, 0.1484375,
0.5, 0.5,
0.5, 0.7109375,
0.5, 0.3984375,
0.75, 0.6484375,
0.5, 0.5,
0.0078125, 0.3984375,
0.25, 0.1484375,
0.25, 0.6484375,
0.5, 0.5,
0.5, 0.078125,
0.5, 0.3984375,
0.25, 0.1484375,
0.5, 0.5,
0.5, 0.7109375,
0.25, 0.6484375,
0.5, 0.3984375,
0.5, 0.5,
0.0078125, 0.3671875,
0.25, 0.09375,
0.25, 0.6484375,
0.5, 0.5,
0.9921875, 0.3671875,
0.7421875, 0.6484375,
0.7421875, 0.09375,
0.5, 0.5,
0.265625, 0.5078125,
0.515625, 0.140625,
0.515625, 0.5078125,
0.5, 0.5,
0.265625, 0.5078125,
0.265625, 0.140625,
0.515625, 0.140625,
0.5, 0.5,
0.5078125, 0.578125,
0.2578125, 0.953125,
0.2578125, 0.578125,
0.5, 0.5,
0.5078125, 0.578125,
0.5078125, 0.953125,
0.2578125, 0.953125,
0.5, 0.5,
0.0234375, 0.5078125,
0.265625, 0.140625,
0.265625, 0.5078125,
0.5, 0.5,
0.0234375, 0.5078125,
0.0234375, 0.140625,
0.265625, 0.140625,
0.5, 0.5,
0.2578125, 0.578125,
0.015625, 0.953125,
0.015625, 0.578125,
0.5, 0.5,
0.2578125, 0.578125,
0.2578125, 0.953125,
0.015625, 0.953125,
0.5, 0.5,
0.515625, 0.5078125,
0.75, 0.140625,
0.75, 0.5078125,
0.5, 0.5,
0.515625, 0.5078125,
0.515625, 0.140625,
0.75, 0.140625,
0.5, 0.5,
0.984375, 0.578125,
0.734375, 0.953125,
0.734375, 0.578125,
0.5, 0.5,
0.984375, 0.578125,
0.984375, 0.953125,
0.734375, 0.953125,
0.5, 0.5,
0.75, 0.5078125,
0.984375, 0.140625,
0.984375, 0.5078125,
0.5, 0.5,
0.75, 0.5078125,
0.75, 0.140625,
0.984375, 0.140625,
0.5, 0.5,
0.5078125, 0.953125,
0.5078125, 0.578125,
0.734375, 0.578125,
0.5, 0.5,
0.734375, 0.578125,
0.734375, 0.953125,
0.5078125, 0.953125,
0.5, 0.5,
0.71875, 0.578125,
0.9296875, 0.25,
0.9296875, 0.578125,
0.5, 0.5,
0.734375, 0.578125,
0.734375, 0.1796875,
0.984375, 0.1796875,
0.5, 0.5,
0.296875, 0.4375,
0.7890625, 0.046875,
0.7890625, 0.4375,
0.5, 0.5,
0.296875, 0.4375,
0.296875, 0.046875,
0.7890625, 0.046875,
0.5, 0.5,
0.984375, 0.5078125,
0.75, 0.8984375,
0.75, 0.5078125,
0.5, 0.5,
0.984375, 0.5078125,
0.984375, 0.8984375,
0.75, 0.8984375,
0.5, 0.5,
0.265625, 0.5078125,
0.0234375, 0.8984375,
0.0234375, 0.5078125,
0.5, 0.5,
0.265625, 0.5078125,
0.265625, 0.8984375,
0.0234375, 0.8984375,
0.5, 0.5,
0.2734375, 0.484375,
0.8203125, 0.046875,
0.8203125, 0.484375,
0.5, 0.5,
0.2734375, 0.484375,
0.2734375, 0.046875,
0.8203125, 0.046875,
0.5, 0.5,
0.015625, 0.578125,
0.2578125, 0.1796875,
0.2578125, 0.578125,
0.5, 0.5,
0.015625, 0.578125,
0.015625, 0.1796875,
0.2578125, 0.1796875,
0.5, 0.5,
};


#define ENN_VERTICES (sizeof(enn_coords)/sizeof(float))/3
#define ENN_FACE_IDXS sizeof(enn_face_idx)/sizeof(int)
#define ENN_UVS (sizeof(enn_uv)/sizeof(float))/2

#endif /* __ENN_DATA_H */