//A program to display and "sing" "99 Bottles of Beer on the Wall"
//Written by Matt Goldman
//Last Updated: 2013-07-30

#define TEMPO 300 //BPM
#define QNOTE (3600/TEMPO)

#define PlayNote(_a,_b) PlayImmediateTone(_a,(_b-3));wait10Msec(_b)

task main(){
  int iBotts=99;
  string sBotts="";
  bool go=true;
  int syls=3;//"nine-ty nine" has 3 syllables
  int nextsyls=0;
  eraseDisplay();
  nVolume=kMaxVolumeLevel;
  while(go){
    //DISPLAY LYRICS
    sprintf(sBotts,"%d",iBotts);
    //need to use these dumb temp strings because ROBOTC 3.60 doesn't let you
    //	put the ?: in the display function arguments
    string temp1=(iBotts>0?sBotts:"No");
    string temp2=(iBotts==1?"":"s");
    //nxtDisplayCenteredTextLine(0,"%s bottle%s of",(iBotts>0?sBotts:"No"),(iBotts==1?"":"s"));
    nxtDisplayCenteredTextLine(0,"%s bottle%s of",temp1,temp2);
    nxtDisplayCenteredTextLine(1,"beer on the wall");
    //nxtDisplayCenteredTextLine(2,"%s bottle%s of",(iBotts>0?sBotts:"No"),(iBotts==1?"":"s"));
    nxtDisplayCenteredTextLine(2,"%s bottle%s of",temp1,temp2);
    nxtDisplayCenteredTextLine(3,"beer!");
    if(iBotts==0){
      nxtDisplayCenteredTextLine(4,"Go to the store,");
      nxtDisplayCenteredTextLine(5,"buy some more,");
      go=false;
    }
    else{
      nxtDisplayCenteredTextLine(4,"Take one down,");
      nxtDisplayCenteredTextLine(5,"pass it around,");
    }
    sprintf(sBotts,"%d",(iBotts==0?iBotts=99:--iBotts));
    temp1=(iBotts>0?sBotts:"No");
    temp2=(iBotts==1?"":"s");
    //nxtDisplayCenteredTextLine(6,"%s bottle%s of",(iBotts>0?sBotts:"No"),(iBotts==1?"":"s"));
    nxtDisplayCenteredTextLine(6,"%s bottle%s of",temp1,temp2);
    nxtDisplayCenteredTextLine(7,"beer on the wall!");

    //add syllables
    if(iBotts/10==7)
      nextsyls=4;
    else if(iBotts/10==1)
      nextsyls=2;
    else if(iBotts/10==0)
      nextsyls=1;
    else
      nextsyls=3;

    if(iBotts%10==7)
      nextsyls++;
    else if(iBotts%10==0)
      nextsyls--;

    if(iBotts==11)
      nextsyls=11;//special case for e-LEV-en
    else if(iBotts==12 || iBotts==0)
      nextsyls=1;

    //PLAY MUSIC
    //FIRST LINE
    if(syls==2){
      PlayNote(587,(2*QNOTE));//sev-
      PlayNote(587,QNOTE);//en
    }
    else if(syls==11){
      PlayNote(587,(QNOTE/2));//e-
      PlayNote(587,(3*QNOTE)/2);//LEV-
      PlayNote(587,(QNOTE));//en
    }
    else{
      for(int i=0;i<syls;++i)
      {PlayNote(587,(3*QNOTE)/syls);}//nine-
    }
    PlayNote(440,QNOTE);//bott-
    PlayNote(440,QNOTE);//les
    PlayNote(440,QNOTE);//of
    PlayNote(587,QNOTE);//beer
    PlayNote(587,QNOTE);//on
    PlayNote(587,QNOTE);//the
    PlayNote(587,3*QNOTE);//wall

    //SECOND LINE
    if(syls==2){
      PlayNote(660,(2*QNOTE));//sev-
      PlayNote(660,QNOTE);//en
    }
    else if(syls==11){
      PlayNote(660,(QNOTE/2));//e-
      PlayNote(660,(3*QNOTE)/2);//LEV-
      PlayNote(660,(QNOTE));//en
    }
    else{
      for(int i=0;i<syls;++i)
      {PlayNote(660,(3*QNOTE)/syls);}//nine-
    }
    PlayNote(494,QNOTE);//bott-
    PlayNote(494,QNOTE);//les
    PlayNote(494,QNOTE);//of
    PlayNote(660,3*QNOTE);//beer!
    PlayNote(0,3*QNOTE);

    //THIRD LINE
    if(iBotts==99){
      PlayNote(554,QNOTE);//go
      PlayNote(554,QNOTE);//to
      PlayNote(554,QNOTE);//the
      PlayNote(554,3*QNOTE);//store
    }
    else{
      PlayNote(554,2*QNOTE);//take
      PlayNote(554,QNOTE);//one
      PlayNote(554,3*QNOTE);//down
    }
    if(iBotts==99){
      PlayNote(554,2*QNOTE);//buy
      PlayNote(554,QNOTE);//some
      PlayNote(554,3*QNOTE);//more
    }
    else{
      PlayNote(554,QNOTE);//pass
      PlayNote(554,QNOTE);//it
      PlayNote(554,QNOTE);//a-
      PlayNote(554,3*QNOTE);//round
    }

    //FOURTH LINE
    if(nextsyls==2){
      PlayNote(440,(2*QNOTE));//sev-
      PlayNote(440,QNOTE);//en
    }
    else if(nextsyls==11){
      PlayNote(440,(QNOTE/2));//e-
      PlayNote(440,(3*QNOTE)/2);//LEV-
      PlayNote(440,(QNOTE));//en
    }
    else{
      for(int i=0;i<nextsyls;++i)
      {PlayNote(440,(3*QNOTE)/nextsyls);}//nine-
    }
    PlayNote(494,QNOTE);//bott-
    PlayNote(494,QNOTE);//les
    PlayNote(554,QNOTE);//of
    PlayNote(587,QNOTE);//beer
    PlayNote(587,QNOTE);//on
    PlayNote(587,QNOTE);//the
    PlayNote(587,3*QNOTE);//wall

    syls=nextsyls;
  }
}
