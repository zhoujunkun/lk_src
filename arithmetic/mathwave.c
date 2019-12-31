/**********************
**math wave file
**********************/
#define SAMPLE_N	128
const uint16_t bwavefile[][SAMPLE_N] ={
{0,0,1,1,2,4,6,8,10,12,15,18,22,25,29,34,38,43,47,52,57,63,68,74,80,86,92,98,104,110,116,123,129,135,142,148,154,160,166,172,178,184,189,195,200,205,210,215,219,224,228,231,235,238,241,244,246,249,250,252,253,254,255,255,255,255,254,253,252,250,249,246,244,241,238,235,231,228,224,219,215,210,205,200,195,189,184,178,172,166,160,154,148,142,135,129,123,116,110,104,98,92,86,80,74,68,63,57,52,47,43,38,34,29,25,22,18,15,12,10,8,6,4,2,1,1,0,0},
{0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,3,3,3,3,3,4,4,4,4,4,5,5,5,5,6,6,6,7,7,7,8,8,8,9,9,10,10,11,11,12,12,13,14,14,15,15,16,17,18,19,19,20,21,22,23,24,25,26,28,29,30,31,33,34,36,37,39,41,43,45,47,49,51,53,55,58,60,63,66,68,71,75,78,81,85,88,92,96,100,105,109,114,119,124,130,135,141,147,154,160,167,174,182,190,198,206,215,225,234,244,255},
{0,0,0,0,0,1,1,1,1,1,1,1,2,2,2,2,2,3,3,3,3,3,4,4,4,4,5,5,5,6,6,6,6,7,7,8,8,8,9,9,10,10,10,11,11,12,12,13,14,14,15,15,16,17,17,18,19,20,21,21,22,23,24,25,26,27,28,29,30,32,33,34,35,37,38,40,41,43,44,46,48,49,51,53,55,57,59,62,64,66,69,71,74,76,79,82,85,88,91,95,98,102,106,109,113,117,122,126,131,135,140,145,150,156,161,167,173,179,186,193,199,207,214,222,230,238,246,255},
{0,21,37,50,61,70,78,85,92,98,103,108,113,117,121,125,128,132,135,138,141,144,147,149,152,154,156,159,161,163,165,167,169,171,173,174,176,178,179,181,182,184,185,187,188,190,191,192,194,195,196,197,199,200,201,202,203,204,205,207,208,209,210,211,212,213,214,214,215,216,217,218,219,220,221,222,222,223,224,225,226,226,227,228,229,229,230,231,232,232,233,234,234,235,236,237,237,238,238,239,240,240,241,242,242,243,243,244,245,245,246,246,247,248,248,249,249,250,250,251,251,252,252,253,253,254,254,255},
{0,4,8,12,16,20,24,28,32,36,40,45,49,53,57,61,65,69,73,77,81,85,89,93,97,101,105,109,113,117,121,125,130,134,138,142,146,150,154,158,162,166,170,174,178,182,186,190,194,198,202,206,210,215,219,223,227,231,235,239,243,247,251,255,251,247,243,239,235,231,227,223,219,215,211,207,203,199,195,191,187,183,179,175,171,167,163,159,155,151,147,143,139,135,131,128,124,120,116,112,108,104,100,96,92,88,84,80,76,72,68,64,60,56,52,48,44,40,36,32,28,24,20,16,12,8,4,0},
{255,253,251,249,247,245,243,241,239,237,235,233,231,229,227,225,223,221,219,217,215,213,211,209,207,205,203,201,199,197,195,193,191,189,187,185,183,181,179,177,175,173,171,169,167,165,163,161,159,157,155,153,151,149,147,145,143,141,139,137,135,133,131,129,126,124,122,120,118,116,114,112,110,108,106,104,102,100,98,96,94,92,90,88,86,84,82,80,78,76,74,72,70,68,66,64,62,60,58,56,54,52,50,48,46,44,42,40,38,36,34,32,30,28,26,24,22,20,18,16,14,12,10,8,6,4,2,0},
{0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,66,68,70,72,74,76,78,80,82,84,86,88,90,92,94,96,98,100,102,104,106,108,110,112,114,116,118,120,122,124,126,129,131,133,135,137,139,141,143,145,147,149,151,153,155,157,159,161,163,165,167,169,171,173,175,177,179,181,183,185,187,189,191,193,195,197,199,201,203,205,207,209,211,213,215,217,219,221,223,225,227,229,231,233,235,237,239,241,243,245,247,249,251,253,255},
{255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,8,16,25,33,41,49,58,66,74,82,90,99,107,115,123,132,140,148,156,165,173,181,189,197,206,214,222,230,239,247,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,247,239,230,222,214,206,197,189,181,173,165,156,148,140,132,123,115,107,99,90,82,74,66,58,49,41,33,25,16,8,0},
{0,38,61,78,92,103,113,121,129,136,142,147,152,157,161,165,169,173,177,180,183,186,189,192,194,197,199,201,204,206,208,210,212,214,216,218,219,221,223,225,226,228,229,231,232,234,235,236,238,239,240,242,243,244,245,246,247,249,250,251,252,253,254,255,218,194,177,164,152,143,134,127,120,114,109,104,99,95,90,87,83,79,76,73,70,67,64,62,59,57,54,52,50,48,46,44,42,40,38,36,35,33,31,30,28,27,25,24,22,21,20,18,17,16,14,13,12,11,10,9,7,6,5,4,3,2,1,0},
{0,38,61,78,92,103,113,121,129,136,142,147,152,157,161,165,169,173,177,180,183,186,189,192,194,197,199,201,204,206,208,210,212,214,216,218,219,221,223,225,226,228,229,231,232,234,235,236,238,239,240,242,243,244,245,246,247,249,250,251,252,253,254,255,235,216,198,182,168,154,142,130,120,110,101,93,85,79,72,66,61,56,51,47,43,40,36,33,31,28,26,24,22,20,18,17,15,14,13,12,11,10,9,8,7,7,6,5,5,4,4,3,3,3,2,2,2,2,1,1,1,1,1,0,0,0,0,0},
{0,38,61,78,92,103,113,121,129,136,142,147,152,157,161,165,169,173,177,180,183,186,189,192,194,197,199,201,204,206,208,210,212,214,216,218,219,221,223,225,226,228,229,231,232,234,235,236,238,239,240,242,243,244,245,246,247,249,250,251,252,253,254,255,251,247,243,239,235,231,227,223,219,215,211,207,203,199,195,191,187,183,179,175,171,167,163,159,155,151,147,143,139,135,131,128,124,120,116,112,108,104,100,96,92,88,84,80,76,72,68,64,60,56,52,48,44,40,36,32,28,24,20,16,12,8,4,0},
{0,21,40,57,74,88,102,115,126,137,146,155,163,171,178,184,190,195,200,205,209,213,216,220,223,225,228,230,232,234,236,238,239,241,242,243,244,245,246,247,248,248,249,250,250,251,251,251,252,252,253,253,253,253,254,254,254,254,254,255,255,255,255,255,218,194,177,164,152,143,134,127,120,114,109,104,99,95,90,87,83,79,76,73,70,67,64,62,59,57,54,52,50,48,46,44,42,40,38,36,35,33,31,30,28,27,25,24,22,21,20,18,17,16,14,13,12,11,10,9,7,6,5,4,3,2,1,0},
{0,21,40,57,74,88,102,115,126,137,146,155,163,171,178,184,190,195,200,205,209,213,216,220,223,225,228,230,232,234,236,238,239,241,242,243,244,245,246,247,248,248,249,250,250,251,251,251,252,252,253,253,253,253,254,254,254,254,254,255,255,255,255,255,218,194,177,164,152,143,134,127,120,114,109,104,99,95,90,87,83,79,76,73,70,67,64,62,59,57,54,52,50,48,46,44,42,40,38,36,35,33,31,30,28,27,25,24,22,21,20,18,17,16,14,13,12,11,10,9,7,6,5,4,3,2,1,0},
{0,21,40,57,74,88,102,115,126,137,146,155,163,171,178,184,190,195,200,205,209,213,216,220,223,225,228,230,232,234,236,238,239,241,242,243,244,245,246,247,248,248,249,250,250,251,251,251,252,252,253,253,253,253,254,254,254,254,254,255,255,255,255,255,251,247,243,239,235,231,227,223,219,215,211,207,203,199,195,191,187,183,179,175,171,167,163,159,155,151,147,143,139,135,131,128,124,120,116,112,108,104,100,96,92,88,84,80,76,72,68,64,60,56,52,48,44,40,36,32,28,24,20,16,12,8,4,0},
{255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};