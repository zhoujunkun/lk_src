#ifndef   __BUZZER_H
#define  __BUZZER_H
//---------------------------------------

//---------------------------------------
#define CENT_C       440*4
/*
1.000000000000000000000000
1.059463094359295264561825
1.122462048309372981433533
1.189207115002721066717500
1.259921049894873164767211
1.334839854170034364830832
1.414213562373095048801689
1.498307076876681498799281
1.587401051968199474751706
1.681792830507429086062251
1.781797436280678609480452
1.887748625363386993283826
2.000000000000000000000000
*/
#if 0
#define FREQ_C  CENT_C
#define FREQ_D  FREQ_C*1.122462048309372981433533
#define FREQ_E  FREQ_C*1.259921049894873164767211
#define FREQ_F  FREQ_C*1.334839854170034364830832
#define FREQ_G  FREQ_C*1.498307076876681498799281
#define FREQ_A  FREQ_C*1.681792830507429086062251
#define FREQ_B  FREQ_C*1.887748625363386993283826
#else
#define FREQ_C  CENT_C
#define FREQ_D  FREQ_C*1.065041089
#define FREQ_E  FREQ_C*1.080059739
#define FREQ_F  FREQ_C*1.090507733
#define FREQ_G  FREQ_C*1.122462048
#define FREQ_A  FREQ_C*1.189207115
#define FREQ_B  FREQ_C*1.414213562
#endif

typedef struct 
{
	int tempo;
	char musicStart;
	const int (*musicPt)[3];
	char playPt;
	char length;
}MusicCtrl_TypeDef;

extern MusicCtrl_TypeDef MusicCtrl;



#define SONG_KEY 1
#define SONG_POWERON 2

extern void    BuzzInit(void );
extern void    StartMusic(char  musicsel);
extern void    MusicControl(void );
extern void    MusicStop(void);
#endif


