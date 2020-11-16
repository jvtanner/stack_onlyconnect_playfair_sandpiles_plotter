/* File: StackOverflow.cpp
 *
 * Cycle of calls: 137, 164, 685, 203, 327, 549, 137
 */
#include "StackOverflow.h"
using namespace std;

/* The "Goto Table" for the Stack Overflow example. This is essentially a function
 * that given a number between 0 and 1023 gives back a number between 0 and 1023.
 * Our function uses this table to make it hard to predict what's going to happen
 * next. Use the debugger to find out!
 *
 */
static constexpr int kGotoTable[] = {
    456,  841,  205,  326,  999,  935,   16,  497,  825,  218,  719,  204,  722,  792,  889,  779,  195, 1008,  776,  834,  587,  652,  498,  973,  428,  676,  876,  148,  126,  374,  190,   76,
    530,  994,  898,  806,   75,  865,   30,  863,   36,  167,    7,  414,  496,  391,  103,  111,  679,   35,  953,   65, 1013,   45,  263,  736,  760,  648,  983,   78,  626,   83,  571,  595,
     73,  877,  887,  666,  319,  275,  443,    9,  646,  257,  746,  526,  163,   53,    6,  726,   51,  485, 1014,  665,  738,  198,  493,  337,  761,  971,   31, 1009,   88,  325,  151,  177,
   1007,  466,  988,  897,  644,  696,  630,  998,  193,  924,  769,  459,  107,  710,  519,  281,  390,  934,  632,  297,  484,  554,  314,  949,   47,   87,  400,  900,  931,  856,  470,   81,
    191,  101,  780,  342,   82,  693,  528,  701,  499,  164,  671,  181,  395,   34,  481,  614,  547,  478,  588,   43,  673,  440,  258,  568,  196,  790,  479,  844,  728,  365,  896,  868,
    592,  283, 1000,  720,  685,  913,  387,  527,  796,  583,   79,   13,  334,  805,  929,  921,  610,  521,  364,  791,  253,  811,  773,  309,  637,  749,  421,  942,  729,  694,  940,  122,
    393,  525, 1012,   74,  559,  371,  869,   12,  581,   24, 1011,  327,  681,  893,  835,  704,   62,  492,  293,  389,  977,  429,  458,  357,  347,  129,  274,  222,   23,  851,  301,  578,
     70,  550,  946,  797,    2,  882,   40,  923, 1017,  885,  173,  462,  133,  329,  503,  997,  402,  359,   32,  132,  970,  185,  490,  225,  565,   28,  843,  510,  223,  707,  532,  338,
     64,  154,  627,  483,  700,  697,  477,  545,  937,  702,    5,  494,  705,  926,  596,   22,  143,  118,  202,  169,  854,  939,  867,  188,  212,  145, 1021,  830,  114,  833,  316,  925,
    649,  708,  838,  373,  216,  658,   77,  757,  340,  514,  339,  380,  593,  403,  566,  230,  981,  616,  174,  277,  706,   71,  640,  352,  576,  460,   14,  333,  574,   46,  793,  131,
    439,  692,  123,  376,   52,  457,   99,  549,   27,  713,  320,  752,  147,  775,   89,  961,  384,   38,  672,  142,  135,   97,  589,  157,  699,  430,  635,  287,  846,  817,  995,  422,
    758,  209,  991,  801,  300,  434,  562,  323,  546,  860,  450,  121,  812,  563,  905, 1006,  611,  508,  774,  310,  754,  990,  798, 1005,  271,  954,  770,  426,  500,  883,  660,  467,
     67,  920,  886,  161,  687,  584,  409,  141,  350,  711,  410,  698,  245,  482,  535,  351,  511,  986,  515,  659,  778,  955,  264,  331,  911,  267,  189,  231,  162,  594,  788,  782,
    794,  677,  747,  814,  399,  992,  468,   18,  850,  891,  144,  582,  343,  522,  613,   92,  839,  168,  909,   93,  933,  972,  247, 1004,  739,  115,  654,  454,  534,  906,  907,  695,
    819,  802,  591,  406,  227,   37,  290,  194,  404,   41,   20,  888,  918,  941,  601,  771,  480,  826,  488,   68,  952,  232,  255,  269,  871,  307,  762,  378,  600,  237,  899,  849,
    932,  413,  980,  186,  950,  651,  415,  645,  784,    0,  551,  725,  670,  661,  930,  721,  564,  620,  233,  317,  197,  976,  242,   44,  506,  433,    1,  140,  318,  328,   95,  653,
    464,  292,  249,  423,  146,  254,  299,   54,  213,  996,   21,  200,  948,  446,  149,  741,  866,  870,  878,  624,  285,  416,  507,  279,  647,  612,  455,  767,  602,   58,   42,  786,
    974,  447,  282,  354,  742,  137,  727,  407, 1002,  915,  348,  539,  385,  335,  236,  912,  577,  689,  813,  958,  628,  548,  124,  884,  179,   26,  605,  465,  951,  171,  441,  420,
    418,  502,  718,  987,  531,  716,  243,  211,   94,  822,  358,   56,  982,  541,  842,  452,  268,  353,  435,  408,  895,  730,   90,  816,  669,  759,  117,  240,  743,  288,  251,  638,
    542,  927,  824,  270,   80,  618,  379,  857, 1019,  967,  278,   39,   15,  853,  375,  308,  208,  349,  960,  158,  425,  524,  294,  703,  228,  733,  445, 1022,  709,  615,  787,  266,
    804,  680,  453,  262,  968,  295,  621,  712,  210,  803,  280,   98,  303,  105,  362,  682,  377,  401,  807,  370,   86,  489,  139,  963,  463,  643,  943,  155,  113,  772,  538,  127,
    599,  634,  633,  567,  715,   50,  663,  206,  427,   29,  112,  523,  272,  203,  845,  346,  580,  956,  229,  902,  777,    3,  109,  650,  381,  674,  872,  558,  723,  737,  472,  892,
    664,   10,  827,   17,  631,  286,  607,  265,  207,  336,  215,  572,  984,  182,  947,  916,  848,  609,  248,  914,  363,  486,  604,   33,  261,  684,  315, 1001,  569,  852,  432,  586,
    537,  516,   57,   60,  160,  120,  110,  556,  517,  656,  306,  451,  509,  298,  642,  828,  745,  629,   66,   96,   84,  361, 1003, 1020,  180,  276,  667,  166,   72,  394,  904,  219,
    192, 1010,  321,  688,  224,  259,  691,  405,  382,  178,  964,  544,  585,    4,  220,  879,  732,  832,  978,  606,  104,  910,  809,  100,  799,  862,  861,  431,  890,  199,  324,  360,
     49,  183,  471,  138,  617,  244,  847,  449,  529,   61,  768,  800,  969,  505,   11,  234,  102,  625,  836,  756,  678,  875,  573,  125, 1016,  683,  579,  312,  962,  473,  152,  686,
    273,  740,  150,  201,  136,  821,  355,  724,  859,  116,  461,  858,  397,  881,  570,   55,  134,  388,  755,  332,  356,  438,  221,   85,  386,  979,  831,  226,  873,  396,  789,  945,
    655,  763,  424,  330,  476,  170,  444,  748,  557,  561,  823,  657,  908,  553,  985,  735,  469,  619,  304, 1018,  130,  781,  874,   69,   48,  810,  598,  957,  217,  345,  623,  734,
     59,  936,  322,  106,  690,  829,  785,  305,  917,  383,  296,  989,  487,  555,  668,  820,  520,  837,  518,  491,   91,  714,  540,  543,  608,  903,   25,  284,  159,  501,  367,  765,
     19,  864,  959,  675,  536,  641,  241,  411,  214,  256,  419,  250,  344,  153,  176,  437,  764,  944,  880, 1015,  165,  840,  108,  533,  965,  235,  815,  442,  302,  291,  922,  560,
    753,  750,  260,  993,  475,  172,  639,  369,  590,  938,  855,  238,  504,  184,  119,  368,  448,  744,  975,  928,  603,  128,  795,  187,  436, 1023,  552,  808,  783,  398,  662,  622,
    311,  372,  392,  513,  289,  366,  495,  474,  597,  246,  417,  575,  894,  512,  717,  731,  751,  313,  252,  175,  966,  412,  636,  818,  239,  766,  341,   63,  901,  919,  156,    8,
};

/**
 * This function is going to trigger a stack overflow. The function takes its argument,
 * uses it as an index into the table, then calls itself using that new index. This
 * recursion never stops, so it eventually crashes the program. We've chosen the
 * particular numbers above because the program eventually calls this function on
 * a certain sequence over and over and over again. Your job is to use the debugger,
 * the stack trace, and the variables window to figure out what the numbers in
 * the sequence are.
 */
void triggerStackOverflow(int index) {
    triggerStackOverflow(kGotoTable[index]);
}
