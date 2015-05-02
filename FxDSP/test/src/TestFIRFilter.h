/*
 *  testFIR.h
 *  Test
 *
 *  Created by Hamilton Kibbe on 4/28/13.
 *  Copyright 2013 HTK Audio. All rights reserved.
 *
 */

#ifndef TESTFIR_H
#define TESTFIR_H


static const float MatlabFilter[22] = 
{
    -0.0018443873850628734,
    -0.0065792468376457691,
    -0.013309495523571968,
    -0.018774356693029404,
    -0.017523109912872314,
    -0.0038088480941951275,
    0.025527413934469223,
    0.068517640233039856,
    0.11734573543071747,
    0.16021603345870972,
    0.18532848358154297,
    0.18532848358154297,
    0.16021603345870972,
    0.11734573543071747,
    0.068517640233039856,
    0.025527413934469223,
    -0.0038088480941951275,
    -0.017523109912872314,
    -0.018774356693029404,
    -0.013309495523571968,
    -0.0065792468376457691,
    -0.0018443873850628734
};

static const float MatlabLowpassOutput[100] =
{
    0.0000000000,
    -0.0003490526,
    -0.0019306202,
    -0.0059612487,
    -0.0133294929,
    -0.0235322434,
    -0.0336053073,
    -0.0376326926,
    -0.0273328889,
    0.0061626267,
    0.0697564930,
    0.1659028232,
    0.2911266387,
    0.4361494482,
    0.5876165628,
    0.7308126688,
    0.8524264097,
    0.9425104260,
    0.9952133894,
    1.0083936453,
    0.9826091528,
    0.9200654030,
    0.8239190578,
    0.6979941726,
    0.5468419194,
    0.3759253919,
    0.1914219409,
    0.0000000000,
    -0.1914219409,
    -0.3759253919,
    -0.5468419194,
    -0.6979941726,
    -0.8239190578,
    -0.9200654030,
    -0.9829581976,
    -1.0103242397,
    -1.0011745691,
    -0.9558399320,
    -0.8759586811,
    -0.7644179463,
    -0.6252492070,
    -0.4634823501,
    -0.2849640250,
    -0.0961463302,
    0.0961463302,
    0.2849640250,
    0.4634823501,
    0.6252492070,
    0.7644179463,
    0.8759586811,
    0.9558399320,
    1.0011745691,
    1.0103242397,
    0.9829581976,
    0.9200654030,
    0.8239190578,
    0.6979941726,
    0.5468419194,
    0.3759253919,
    0.1914219409,
    0.0000000000,
    -0.1914219409,
    -0.3759253919,
    -0.5468419194,
    -0.6979941726,
    -0.8239190578,
    -0.9200654030,
    -0.9829581976,
    -1.0103242397,
    -1.0011745691,
    -0.9558399320,
    -0.8759586811,
    -0.7644179463,
    -0.6252492070,
    -0.4634823501,
    -0.2849640250,
    -0.0961463302,
    0.0961463302,
    0.2849640250,
    0.4634823501,
    0.6252492070,
    0.7644179463,
    0.8759586811,
    0.9558399320,
    1.0011745691,
    1.0103242397,
    0.9829581976,
    0.9200654030,
    0.8239190578,
    0.6979941726,
    0.5468419194,
    0.3759253919,
    0.1914219409,
    0.0000000000,
    -0.1914219409,
    -0.3759253919,
    -0.5468419194,
    -0.6979941726,
    -0.8239190578,
    -0.9200654030,
};
/*
static const float MatlabLowpassOutput[100] = 
{
    0, -0.00034560373751446605, -0.0019117922056466341, -0.0059042051434516907,
    -0.013205422088503838, -0.023322334513068199, -0.033326748758554459,
    -0.037367187440395355, -0.027244947850704193, 0.0058308583684265614,
    0.068721584975719452, 0.16390492022037506, 0.2880089282989502,
    0.43193158507347107, 0.58254122734069824, 0.72535300254821777,
    0.84725207090377808, 0.93842333555221558,0.99306684732437134,
    1.0090122222900391, 0.98671919107437134, 0.9282383918762207,
    0.83652853965759277, 0.71518415212631226, 0.56850415468215942,
    0.40168452262878418, 0.22063513100147247, 0.031769569963216782,
    -0.15822148323059082, -0.34260740876197815, -0.51485627889633179,
    -0.66886615753173828, -0.79918116331100464, -0.90118467807769775,
    -0.97126328945159912, -1.006934642791748, -1.006934642791748,
    -0.97126328945159912, -0.90118473768234253, -0.79918110370635986,
    -0.66886609792709351, -0.51485633850097656, -0.34260737895965576,
    -0.15822146832942963, 0.031769577413797379, 0.22063511610031128,
    0.40168458223342896, 0.5685042142868042, 0.71518427133560181,
    0.83652853965759277, 0.92823827266693115, 0.98706477880477905,
    1.0109243392944336, 0.99897086620330811, 0.95162868499755859,
    0.87057435512542725, 0.75867974758148193, 0.61990845203399658,
    0.45917654037475586, 0.28217807412147522, 0.095183342695236206,
    -0.095183342695236206, -0.28217807412147522, -0.45917651057243347,
    -0.61990845203399658, -0.75867974758148193, -0.87057441473007202,
    -0.95162880420684814, -0.99897104501724243, -1.0109241008758545,
    -0.98706477880477905, -0.9282383918762207, -0.83652853965759277,
    -0.71518415212631226, -0.56850415468215942, -0.40168452262878418,
    -0.22063513100147247, -0.031769569963216782, 0.15822148323059082,
    0.34260740876197815, 0.51485627889633179, 0.66886615753173828,
    0.79918116331100464, 0.90118467807769775, 0.97126328945159912,
    1.006934642791748, 1.006934642791748, 0.97126328945159912,
    0.90118473768234253, 0.79918110370635986, 0.66886609792709351,
    0.51485633850097656, 0.34260737895965576, 0.15822146832942963,
    -0.03176957368850708, -0.22063511610031128, -0.40168458223342896,
    -0.5685042142868042, -0.71518427133560181, -0.83652853965759277
};
*/

static const double MatlabFilterD[22] =
{
    -0.0018443873850628734,
    -0.0065792468376457691,
    -0.013309495523571968,
    -0.018774356693029404,
    -0.017523109912872314,
    -0.0038088480941951275,
    0.025527413934469223,
    0.068517640233039856,
    0.11734573543071747,
    0.16021603345870972,
    0.18532848358154297,
    0.18532848358154297,
    0.16021603345870972,
    0.11734573543071747,
    0.068517640233039856,
    0.025527413934469223,
    -0.0038088480941951275,
    -0.017523109912872314,
    -0.018774356693029404,
    -0.013309495523571968,
    -0.0065792468376457691,
    -0.0018443873850628734
};



static const double MatlabLowpassOutputD[100] =
{
    0.0000000000000000000,
    -0.0003490526077057918,
    -0.0019306201957001530,
    -0.0059612487292853584,
    -0.0133294925681341336,
    -0.0235322441719917237,
    -0.0336053084002155833,
    -0.0376326943726770710,
    -0.0273328880447394930,
    0.0061626265229309130,
    0.0697564914100457095,
    0.1659028210820707172,
    0.2911266366778403336,
    0.4361494607995693440,
    0.5876165334823169051,
    0.7308126622998101229,
    0.8524264122403708566,
    0.9425104214258044344,
    0.9952133779378832257,
    1.0083936596019005272,
    0.9826091284742065612,
    0.9200654126293633661,
    0.8239190829573382890,
    0.6979941709270033323,
    0.5468419309532919215,
    0.3759253988121749046,
    0.1914219432939128496,
    0.0000000000000001997,
    -0.1914219432939124887,
    -0.3759253988121745160,
    -0.5468419309532918104,
    -0.6979941709270028882,
    -0.8239190829573381780,
    -0.9200654126293631441,
    -0.9829581810819122412,
    -1.0103242797976008660,
    -1.0011746266671686101,
    -0.9558399139939386391,
    -0.8759586564123628127,
    -0.7644179707000260393,
    -0.6252492278549941496,
    -0.4634823488443091666,
    -0.2849640101549096305,
    -0.0961463296720251742,
    0.0961463296720248828,
    0.2849640101549092974,
    0.4634823488443086670,
    0.6252492278549937055,
    0.7644179707000255952,
    0.8759586564123622576,
    0.9558399139939385281,
    1.0011746266671686101,
    1.0103242797976006440,
    0.9829581810819124632,
    0.9200654126293634771,
    0.8239190829573384001,
    0.6979941709270033323,
    0.5468419309532918104,
    0.3759253988121749601,
    0.1914219432939128496,
    0.0000000000000002123,
    -0.1914219432939124055,
    -0.3759253988121742940,
    -0.5468419309532913664,
    -0.6979941709270025552,
    -0.8239190829573377339,
    -0.9200654126293628110,
    -0.9829581810819120191,
    -1.0103242797976006440,
    -1.0011746266671683880,
    -0.9558399139939385281,
    -0.8759586564123631458,
    -0.7644179707000262614,
    -0.6252492278549941496,
    -0.4634823488443093331,
    -0.2849640101549097415,
    -0.0961463296720252159,
    0.0961463296720249105,
    0.2849640101549094084,
    0.4634823488443088890,
    0.6252492278549938165,
    0.7644179707000257062,
    0.8759586564123623686,
    0.9558399139939383060,
    1.0011746266671683880,
    1.0103242797976006440,
    0.9829581810819124632,
    0.9200654126293635882,
    0.8239190829573385111,
    0.6979941709270033323,
    0.5468419309532924766,
    0.3759253988121755152,
    0.1914219432939135157,
    0.0000000000000008700,
    -0.1914219432939117949,
    -0.3759253988121737389,
    -0.5468419309532910333,
    -0.6979941709270022221,
    -0.8239190829573372898,
    -0.9200654126293624779,
};

/*
static const double MatlabLowpassOutputD[100] =
{
    0, -0.00034560373751446605, -0.0019117922056466341, -0.0059042051434516907,
    -0.013205422088503838, -0.023322334513068199, -0.033326748758554459,
    -0.037367187440395355, -0.027244947850704193, 0.0058308583684265614,
    0.068721584975719452, 0.16390492022037506, 0.2880089282989502,
    0.43193158507347107, 0.58254122734069824, 0.72535300254821777,
    0.84725207090377808, 0.93842333555221558,0.99306684732437134,
    1.0090122222900391, 0.98671919107437134, 0.9282383918762207,
    0.83652853965759277, 0.71518415212631226, 0.56850415468215942,
    0.40168452262878418, 0.22063513100147247, 0.031769569963216782,
    -0.15822148323059082, -0.34260740876197815, -0.51485627889633179,
    -0.66886615753173828, -0.79918116331100464, -0.90118467807769775,
    -0.97126328945159912, -1.006934642791748, -1.006934642791748,
    -0.97126328945159912, -0.90118473768234253, -0.79918110370635986,
    -0.66886609792709351, -0.51485633850097656, -0.34260737895965576,
    -0.15822146832942963, 0.031769577413797379, 0.22063511610031128,
    0.40168458223342896, 0.5685042142868042, 0.71518427133560181,
    0.83652853965759277, 0.92823827266693115, 0.98706477880477905,
    1.0109243392944336, 0.99897086620330811, 0.95162868499755859,
    0.87057435512542725, 0.75867974758148193, 0.61990845203399658,
    0.45917654037475586, 0.28217807412147522, 0.095183342695236206,
    -0.095183342695236206, -0.28217807412147522, -0.45917651057243347,
    -0.61990845203399658, -0.75867974758148193, -0.87057441473007202,
    -0.95162880420684814, -0.99897104501724243, -1.0109241008758545,
    -0.98706477880477905, -0.9282383918762207, -0.83652853965759277,
    -0.71518415212631226, -0.56850415468215942, -0.40168452262878418,
    -0.22063513100147247, -0.031769569963216782, 0.15822148323059082,
    0.34260740876197815, 0.51485627889633179, 0.66886615753173828,
    0.79918116331100464, 0.90118467807769775, 0.97126328945159912,
    1.006934642791748, 1.006934642791748, 0.97126328945159912,
    0.90118473768234253, 0.79918110370635986, 0.66886609792709351,
    0.51485633850097656, 0.34260737895965576, 0.15822146832942963,
    -0.03176957368850708, -0.22063511610031128, -0.40168458223342896,
    -0.5685042142868042, -0.71518427133560181, -0.83652853965759277
};
*/
#endif
