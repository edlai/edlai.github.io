Цр╜             y Tree_V      Tree_HEADER K    SUBTYPE I  Binary 	Tree_DATA K    SUBTYPE I  Binary          Цр╜             Tree_PWD I    WIDTH    Tree_COMPRESSED      
Tree_TITLE I    WIDTH    Tree_SUBJECT I    WIDTH    Tree_AUTHOR I    WIDTH    Tree_COMPANY I    WIDTH    Tree_COMMENTS I    WIDTH    Tree_RO         А            Zж  Цр╜             JNode_MASTER      Node_DETAIL      	Node_ITEM I    WIDTH   	Node_DATA K    SUBTYPE I 
 Formatted Node_AUTOINC    SUBTYPE I  Autoinc Node_SELECTED      
Node_IMAGE      Node_BMNAME I    WIDTH    	Node_UNIQ      
Node_COLOR      	Node_FLAG       AUTOINCVALUE       А         RootН   {\rtf1\ansi\deff0{\fonttbl{\f0\fnil\fcharset0 Verdana;}}
{\*\generator Riched20 5.40.11.2210;}\viewkind4\uc1\pard\lang1033\f0\fs20\par
}
      =                А        CЯ  {\rtf1\ansi\ansicpg1252\deff0{\fonttbl{\f0\fnil\fcharset0 Verdana;}}
{\colortbl ;\red0\green0\blue255;}
{\*\generator Riched20 5.40.11.2210;}\viewkind4\uc1\pard\lang1033\f0\fs20\u30001?\u26044?\u25105?\u23565? Linux C \u20063?\u19981?\u26159?\u24456?\u29087?\u24713? \u25152?\u20197?\u25353?\u29031?\u31243?\u24335?\u-26880?\u27714?\u21443?\u-32765?\u24190?\u20221?\u25991?\u20214?\u20006?\u20808?\u23531?\u20102?\u24190?\u20491?\u23567?\u31243?\u24335?\u28204?\u-30106?\u19968?\u19979?\par
\par
Linux C \u19978?\u30340?\u22522?\u26412?\u-30050?\u27861?\par
\par
\u22312?Linux C\u19978?\u30340? kbhit() \par
Linux C \u20006?\u27794?\u26377?\u-26530?\u20284?MS-DOS\u19978?\u30340?kbhit\u25152?\u20197?\u-30335?\u-32278?\u24049?\u23531?\par
\par
Linux C\u19978?\u20197? root \u27402?\u-27056?\u25511?\u21046? I/O\par
\u22522?\u26412?\u25511?\u21046?\par
\par
\par
Linux \u19978?\u30340? C \u-30050?\u-30208?\u21443?\u-32765?\u25991?\u20214?\par
{\field{\*\fldinst{HYPERLINK "http://gcc.gnu.org/"}}{\fldrslt{\ul\cf1 http://gcc.gnu.org/}}}\f0\fs20\par
\par
\par
\u22312?Linux C\u19978?\u30340? kbhit() :: kbhit() MSDOS equivalent in Linux\par
{\field{\*\fldinst{HYPERLINK "http://www.control.auc.dk/~jnn/c2000/programs/mm5/keyboardhit/msg02541.html"}}{\fldrslt{\ul\cf1 http://www.control.auc.dk/~jnn/c2000/programs/mm5/keyboardhit/msg02541.html}}}\f0\fs20\par
\par
Linux \u19978?\u30340? I/O\u25511?\u21046?\par
\par
}
      =                         C++}  {\rtf1\ansi\ansicpg1252\deff0{\fonttbl{\f0\fnil\fcharset0 Verdana;}}
{\colortbl ;\red0\green0\blue255;}
{\*\generator Riched20 5.40.11.2210;}\viewkind4\uc1\pard\lang1033\f0\fs20\par
{\field{\*\fldinst{HYPERLINK "http://www.mathcs.carleton.edu/courses/course_resources/cs117/"}}{\fldrslt{\ul\cf1 http://www.mathcs.carleton.edu/courses/course_resources/cs117/}}}\f0\fs20\par
}
      =                 @         honework     =                           helloJ  {\rtf1\ansi\ansicpg1252\deff0{\fonttbl{\f0\fnil\fcharset0 Verdana;}}
{\*\generator Riched20 5.40.11.2210;}\viewkind4\uc1\pard\lang1033\f0\fs20 /*\par
\par
Filename ::        hello.c\par
compile command :  gcc -O -o hello hello.c\par
\par
Auther : Jing-Wen.Lai\par
\u30446?\u30340? :: Linux C  \u30340?\u22522?\u26412?\u28204?\u-30106?\u-244?\u21360?\u20986? Hello, world\u12290? \par
\u26085?\u26399? :: 3/22 2003\par
\par
*/\par
\par
#include <stdio.h>\par
int main(int argc, char *argv[])\par
\{\par
\tab printf("Hello, world\\n");\par
\tab return 0;\par
\}\par
}
      =                           kb  {\rtf1\ansi\ansicpg1252\deff0{\fonttbl{\f0\fnil\fcharset0 Verdana;}}
{\colortbl ;\red0\green0\blue255;}
{\*\generator Riched20 5.40.11.2210;}\viewkind4\uc1\pard\lang1033\f0\fs20 /*\par
\par
Filename ::        kb.c\par
compile command :  gcc -O -o kb kb.c\par
\par
Auther : Jing-Wen.Lai\par
\u30446?\u30340? :: \u24179?\u24120?\u22519?\u-30644? Loop \u21360?\u20986? \u-30200?\u25976? \u-30198?\u24687? \u-244?\u-27036?\u-26786?\u-27787?\u30436?\u25353?\u19979? 'q' \u-27787? \u21063?\u-26910?\u-27253?\u-30200?\u25976? Loop \u12290? \par
\u21443?\u-32765? :: \u21443?\u-32765?\u32178?\u-29201?\u25991?\u20214?({\field{\*\fldinst{HYPERLINK "http://www.control.auc.dk/~jnn/c2000/programs/mm5/keyboardhit/msg02541.html"}}{\fldrslt{\ul\cf1 http://www.control.auc.dk/~jnn/c2000/programs/mm5/keyboardhit/msg02541.html}}}\f0\fs20 )\u25913?\u23531?\u12290?\par
\u26085?\u26399? :: 3/22 2003\par
\par
*/\par
\par
#include <stdio.h>\par
#include <termios.h>\par
\par
static struct termios orig, new;\par
static int peek = -1;\par
\par
int main()\par
\{\par
  \par
  int ch =0;          /*  \u-27787?\u30436?\u25152?\u25353?\u19979?\u30340?\u23383?\u20803? */\par
  int loopCount=1;    /*  Loop \u29992? \u-30200?\u25976?\u22120?   */\par
\par
  tcgetattr(0, &orig);\par
  new = orig; new.c_lflag &= ~ICANON; new.c_lflag &= ~ECHO; new.c_lflag &= ~ISIG;\par
  new.c_cc[VMIN] = 1; new.c_cc[VTIME] = 0; tcsetattr(0, TCSANOW, &new);\par
\par
  /* =========================== */\par
  /* [[ \u30070?\u-28872?\u20837?\u23383?\u20803?\u19981?\u28858? q \u26178?  ]]  */\par
  /* =========================== */\par
\par
  while(ch != 'q') \{\par
    printf("looping %d times \\n",loopCount);\par
    sleep(1); loopCount++;\par
\par
    if(kbhit()) \{\par
        ch = readch();\par
        printf("== Input %c ==\\n",ch);\par
    \}\par
\par
  \}\par
\par
  /* ======================== */\par
  /* [[  \u-28872?\u20837?\u23383?\u20803? \u28858? q \u26178?  ]] */\par
  /* ======================== */\par
\par
  printf("== Quit == \\n");\par
  tcsetattr(0,TCSANOW, &orig);\par
  exit(0);\par
\par
\}\par
\par
/* ======================= */\par
/*   sub Function          */\par
/* ======================= */\par
int kbhit()\par
\{\par
    char ch;int nread;\par
    if(peek != -1) return 1;\par
    new.c_cc[VMIN]=0;\par
    tcsetattr(0, TCSANOW, &new);\par
    nread = read(0,&ch,1);\par
    new.c_cc[VMIN]=1;\par
    tcsetattr(0, TCSANOW, &new);    \par
\tab if(nread == 1) \{\par
\tab     peek = ch;\par
        return 1;\par
    \}\par
    return 0;\par
\}\par
\par
int readch()\par
\{\par
    char ch;\par
    if(peek != -1) \{\par
        ch = peek;\par
        peek = -1;\par
        return ch;\par
    \}\par
    read(0,&ch,1);\par
    return ch;\par
\}\par
\par
}
      =                  А        ioъ	  {\rtf1\ansi\ansicpg1252\deff0{\fonttbl{\f0\fnil\fcharset0 Verdana;}}
{\colortbl ;\red0\green0\blue255;}
{\*\generator Riched20 5.40.11.2210;}\viewkind4\uc1\pard\lang1033\f0\fs20 /*\par
     --  io.c  <Linux I/O \u22496? \u22522?\u26412?\u28204?\u-30106? -- \u28204?\u-30106? \u21083?\u32068?\u-30499?\u23436?\u25104?\u30340? IO \u26495?\u29992?>  --\par
\par
     Auther : Jing-Wen.Lai\par
\tab  \u21205?\u20316? : \u20197? Linux C \u25511?\u21046? 8255 I/O \u23526?\u-26025?\u26495?\u19978?\u30340? LED \u-244?\par
     \u32232?\u-29841? : \u20351?\u29992? `gcc -O2 -o io io.c',\par
     \u22519?\u-30644? : \u20197? root \u30340?\u-29013?\u20221?\u22519?\u-30644? `./io'.\par
     \u21443?\u-32765? : \u30001?<<CLDP -- Linux \u20013?\u25991?\u25991?\u20214?\u-30200?\u21123?>>\u25913?\u23531?\par
            {\field{\*\fldinst{HYPERLINK "http://www.linux.org.tw/CLDP/mini/IO-Port-Programming-9.html"}}{\fldrslt{\ul\cf1 http://www.linux.org.tw/CLDP/mini/IO-Port-Programming-9.html}}}\f0\fs20                                                                                                        \par
*/\par
#include <stdio.h>\par
#include <unistd.h>\par
#include <asm/io.h>\par
\par
#define CCW 0x303  /* 8255 CCW */\par
#define PA  0x300   /* 8255 PORT A */\par
int main()\par
\{\par
    int i=0;\par
\par
    /* \u21462?\u24471?\u22496?\u20301?\u22336?\u30340?\u23384?\u21462?\u27402?\u-27056? */\par
    if (ioperm(CCW, 3, 1)) \{perror("ioperm"); exit(1);\}\par
    if (ioperm(PA, 3, 1))  \{perror("ioperm"); exit(1);\}\par
\par
    /* \u23450?\u32681? 8255 \u24037?\u20316?\u27169?\u24335? */\par
    outb(0x80, CCW);\par
\par
    /* \u-28211?\u32622? 8255 PORT A \u30340?\u-28872?\u20986?\u-29497?\u26009?\u20449?\u-31137? (D0-7) \u20840?\u28858?\u-26890? (0) */\par
    outb(0, PA);\par
\par
    /* LED   \u20132?\u20114? \u-27261?\u29197? 10 \u27425? \u-244?\u27599?\u27425? 1000 ms */\par
    for (i=1; i<=10; i++)\{\par
    usleep(1000000);        \par
        if(i%2 == 0)\{\par
          outb( 0x00, PA);\par
          printf("-X-  step: %d\\n",i); \par
        \}else\{\par
          outb( 0xFF, PA);\par
          printf("-O-  step: %d\\n",i);\par
        \}\par
    \} \par
\par
   /* \u25105?\u20497?\u19981?\u20877?\u-26880?\u-30335?\u-28647?\u20123?\u22496?\u20301?\u22336? */\par
   if (ioperm(CCW, 3, 0)) \{perror("ioperm"); exit(1);\}\par
   if (ioperm(PA, 3, 0))  \{perror("ioperm"); exit(1);\}\par
   exit(0);\par
\par
 /* \u32080?\u26463? io.c */\par
\}\par
}
      =               @А        testing     =               @А 	       product	     =   	             А 
   	    blink╩  {\rtf1\ansi\deff0{\fonttbl{\f0\fnil\fcharset0 Verdana;}}
{\*\generator Riched20 5.40.11.2210;}\viewkind4\uc1\pard\lang1033\f0\fs20 /*\par
\par
Filename ::        blink.c\par
compile command :  gcc -O -o blink blink.c\par
\par
Auther : Jing-Wen.Lai\par
\u30446?\u30340? :: \u24179?\u24120?\u22519?\u-30644? Loop \u21360?\u20986? \u-30200?\u25976? \u-30198?\u24687? \u-244? 8255 I/O \u23526?\u-26025?\u26495?\u19978?\u30340? LED \u20134?\u-26968?\u20043?\u-27261?\u29197?\par
\tab\tab\u-27036?\u-26786?\u-27787?\u30436?\u25353?\u19979? 'q' \u-27787? \u21063?\u-26910?\u-27253?\u-30200?\u25976? Loop \u12290? \par
\u26085?\u26399? :: 3/22 2003\par
\par
*/\par
\par
#include <stdio.h>\par
#include <termios.h>\par
#include <unistd.h>\par
#include <asm/io.h>\par
\par
#define CCW 0x303   /* 8255 CCW */\par
#define PA  0x300   /* 8255 PORT A */\par
\par
static struct termios orig, new;\par
static int peek = -1;\par
\par
int main()\par
\{\par
  \par
  int ch =0;          /*  \u-27787?\u30436?\u25152?\u25353?\u19979?\u30340?\u23383?\u20803? */\par
  int loopCount=1;    /*  Loop \u29992? \u-30200?\u25976?\u22120?   */\par
\par
  tcgetattr(0, &orig);\par
  new = orig; new.c_lflag &= ~ICANON; new.c_lflag &= ~ECHO; new.c_lflag &= ~ISIG;\par
  new.c_cc[VMIN] = 1; new.c_cc[VTIME] = 0; tcsetattr(0, TCSANOW, &new);\par
\par
  /* \u21462?\u24471?\u22496?\u20301?\u22336?\u30340?\u23384?\u21462?\u27402?\u-27056? */\par
  if (ioperm(CCW, 3, 1)) \{perror("ioperm"); exit(1);\}\par
  if (ioperm(PA, 3, 1))  \{perror("ioperm"); exit(1);\}\par
  \par
  /* \u23450?\u32681? 8255 \u24037?\u20316?\u27169?\u24335? */\par
  outb(0x80, CCW);\par
\par
  /* \u-28211?\u32622? 8255 PORT A \u30340?\u-28872?\u20986?\u-29497?\u26009?\u20449?\u-31137? (D0-7) \u20840?\u28858?\u-26890? (0) */\par
  outb(0, PA);\par
\par
  /* =========================== */\par
  /* [[ \u30070?\u-28872?\u20837?\u23383?\u20803?\u19981?\u28858? q \u26178?  ]]  */\par
  /* =========================== */\par
\par
  /*  LED  \u20132?\u20114? \u-27261?\u29197?  */\par
   \par
  while(ch != 'q') \{\par
    //printf("looping %d times \\n",loopCount);\par
\par
    sleep(1); loopCount++;\par
\par
    if(loopCount %2 == 0)\{\par
          outb( 0x00, PA);\par
          printf("-X-  step: %d\\n",loopCount); \par
    \}else\{\par
          outb( 0xFF, PA);\par
          printf("-O-  step: %d\\n",loopCount);\par
    \}\par
\par
    if(kbhit()) \{\par
        ch = readch();\par
    \}\par
  \}\par
\par
  /* ======================== */\par
  /* [[  \u-28872?\u20837?\u23383?\u20803? \u28858? q \u26178?  ]] */\par
  /* ======================== */\par
  \par
  //  LED \u19981?\u20142? \par
  outb( 0x00, PA);\par
\par
  /* \u25105?\u20497?\u19981?\u20877?\u-26880?\u-30335?\u-28647?\u20123?\u22496?\u20301?\u22336? */\par
  if (ioperm(CCW, 3, 0)) \{perror("ioperm"); exit(1);\}\par
  if (ioperm(PA, 3, 0))  \{perror("ioperm"); exit(1);\}\par
  \par
  printf("== Quit == \\n");\par
  tcsetattr(0,TCSANOW, &orig);\par
  exit(0);\par
\par
\}\par
\par
/* ======================= */\par
/*   sub Function          */\par
/* ======================= */\par
int kbhit()\par
\{\par
    char ch;int nread;\par
    if(peek != -1) return 1;\par
    new.c_cc[VMIN]=0;\par
    tcsetattr(0, TCSANOW, &new);\par
    nread = read(0,&ch,1);\par
    new.c_cc[VMIN]=1;\par
    tcsetattr(0, TCSANOW, &new);    \par
\tab if(nread == 1) \{\par
\tab     peek = ch;\par
        return 1;\par
    \}\par
    return 0;\par
\}\par
\par
int readch()\par
\{\par
    char ch;\par
    if(peek != -1) \{\par
        ch = peek;\par
        peek = -1;\par
        return ch;\par
    \}\par
    read(0,&ch,1);\par
    return ch;\par
\}\par
\par
}
 
     =   
            @А    	    pili     =               @А        pili_test.c     =                А        helloв  {\rtf1\ansi\ansicpg1252\deff0{\fonttbl{\f0\fnil\fcharset0 Verdana;}}
{\*\generator Riched20 5.40.11.2210;}\viewkind4\uc1\pard\lang1033\f0\fs20 /*\par
Filename ::        hello.cpp\par
compile command :  g++  -Wno-deprecated -ohello hello.cpp\par
\par
\u30446?\u30340? ::  C ++ \u30340?\u22522?\u26412?\u28204?\u-30106?\u-244?\u21360?\u20986? Hello C++!\u12290? \par
\u21443?\u-32765? :                                                                                                        \par
\u26085?\u26399? :: 3/23 2003\par
*/\par
\par
#include <iostream.h>\par
int main() \{\tab\par
\tab cout << "Hello C++ !" << endl;\par
\tab return (0);\par
\}\par
}
      =                         stopN	  {\rtf1\ansi\deff0{\fonttbl{\f0\fnil\fcharset0 Verdana;}}
{\*\generator Riched20 5.40.11.2210;}\viewkind4\uc1\pard\lang1033\f0\fs20\par
\par
/*\par
\par
Filename ::        stop.c\par
compile command :  g++ -O -o stop stop.c\par
\par
\u30446?\u30340? ::  \u25353?\u20219?\u24847?\u-27787?\u26371?\u20572?\u27490?\u12290? \par
\u21443?\u-32765? :: \u12290?\par
\u26085?\u26399? :: 3/22 2003\par
\par
*/\par
\par
#include <stdio.h>\par
#include <termios.h>\par
#include <unistd.h>\par
#include <sys/io.h>\par
\par
static struct termios orig, neww;\par
static int peek = -1;\par
\par
int main()\par
\{\par
  \par
  int ch =0;          /*  \u-27787?\u30436?\u25152?\u25353?\u19979?\u30340?\u23383?\u20803? */\par
  int loopCount=1;    /*  Loop \u29992? \u-30200?\u25976?\u22120?   */\par
\par
  int kbhit(); \par
  int readch();\par
\par
  tcgetattr(0, &orig);\par
  neww = orig; neww.c_lflag &= ~ICANON; neww.c_lflag &= ~ECHO; neww.c_lflag &= ~ISIG;\par
  neww.c_cc[VMIN] = 1; neww.c_cc[VTIME] = 0; tcsetattr(0, TCSANOW, &neww);\par
\par
  /* =========================== */\par
  /* [[ \u30070?\u-28872?\u20837?\u23383?\u20803?\u19981?\u28858? q \u26178?  ]]  */\par
  /* =========================== */\par
\par
 while(!kbhit()) \{\par
    printf("looping %d time(s) . Press anyKey Will Stop the Counter \\n",loopCount);\par
    sleep(1); loopCount++;\par
  \}\par
\par
\par
  /* ======================== */\par
  /* [[  \u-28872?\u20837?\u23383?\u20803? \u28858? q \u26178?  ]] */\par
  /* ======================== */\par
\par
  printf("== Stop == \\n");\par
  tcsetattr(0,TCSANOW, &orig);\par
  return (0);\par
\par
\}\par
\par
/* ======================= */\par
/*   sub Function          */\par
/* ======================= */\par
int kbhit()\par
\{\par
    char ch;int nread;\par
    if(peek != -1) return 1;\par
    neww.c_cc[VMIN]=0;\par
    tcsetattr(0, TCSANOW, &neww);\par
    nread = read(0,&ch,1);\par
    neww.c_cc[VMIN]=1;\par
    tcsetattr(0, TCSANOW, &neww);    \par
\tab if(nread == 1) \{\par
\tab     peek = ch;\par
        return 1;\par
    \}\par
    return (0);\par
\}\par
\par
int readch()\par
\{\par
    char ch;\par
    if(peek != -1) \{\par
        ch = peek;\par
        peek = -1;\par
        return ch;\par
    \}\par
    read(0,&ch,1);\par
    return ch;\par
\}\par
\par
}
      =                           io╧  {\rtf1\ansi\deff0{\fonttbl{\f0\fnil\fcharset0 Verdana;}}
{\colortbl ;\red0\green0\blue255;}
{\*\generator Riched20 5.40.11.2210;}\viewkind4\uc1\pard\lang1033\f0\fs20 /*\par
     --  io.cpp  <Linux I/O \u22496? \u22522?\u26412?\u28204?\u-30106? -- \u28204?\u-30106? \u21083?\u32068?\u-30499?\u23436?\u25104?\u30340? IO \u26495?\u29992?>  --\par
     \u21205?\u20316? :\par
     \u32232?\u-29841? : \u20351?\u29992? `g++ -O -o io io.cpp',\par
     \u22519?\u-30644? : \u20197? root \u30340?\u-29013?\u20221?\u22519?\u-30644? `./io'.\par
     \u21443?\u-32765? : \u30001?<<CLDP -- Linux \u20013?\u25991?\u25991?\u20214?\u-30200?\u21123?>>\u25913?\u23531?\par
            {\field{\*\fldinst{HYPERLINK "http://www.linux.org.tw/CLDP/mini/IO-Port-Programming-9.html"}}{\fldrslt{\ul\cf1 http://www.linux.org.tw/CLDP/mini/IO-Port-Programming-9.html}}}\f0\fs20\par
*/\par
#include <stdio.h>\par
#include <unistd.h>\par
#include <sys/io.h>\par
\par
 #define CCW 0x303  /* 8255 CCW */\par
 #define PA 0x300   /* 8255 PORT A */\par
 int main()\par
 \{\par
   /* \u21462?\u24471?\u22496?\u20301?\u22336?\u30340?\u23384?\u21462?\u27402?\u-27056? */\par
   if (ioperm(CCW, 3, 1)) \{perror("ioperm"); return (0);\}\par
   if (ioperm(PA, 3, 1)) \{perror("ioperm"); return (0);\}\par
\par
   /* \u23450?\u32681? 8255 \u24037?\u20316?\u27169?\u24335? */\par
   outb(0x80, CCW);\par
\par
   /* \u-28211?\u32622? 8255 PORT A \u30340?\u-28872?\u20986?\u-29497?\u26009?\u20449?\u-31137? (D0-7) \u20840?\u28858?\u-26890? (0) */\par
   outb(0, PA);\par
\par
   /* PILI \u29128?  (1000 ms) \u20132?\u20114? \u-27261?\u29197? */\par
   for (int i=1; i<=10; i++)\{\par
    usleep(1000000);       \par
        if(i%2 == 0)\{\par
          outb( 0x00, PA);\par
          printf("-X-  step: %d\\n",i);\par
        \}else\{\par
          outb( 0xFF, PA);\par
          printf("-O-  step: %d\\n",i);\par
        \}\par
    \}\par
\par
   /* \u25105?\u20497?\u19981?\u20877?\u-26880?\u-30335?\u-28647?\u20123?\u22496?\u20301?\u22336? */\par
   if (ioperm(CCW, 3, 0)) \{perror("ioperm"); return (0);\}\par
   if (ioperm(PA, 3, 0))  \{perror("ioperm"); return (0);\}\par
   return (0);\par
 \}\par
\par
 /* \u32080?\u26463? example.c */\par
}
      =                 @         stop_io     =                           -- клеє м[║c --п  {\rtf1\ansi\deff0{\fonttbl{\f0\fnil\fcharset0 Verdana;}}
{\*\generator Riched20 5.40.11.2210;}\viewkind4\uc1\pard\lang1033\f0\fs20\u23459?\u21578?\u26684?\u24335?\par
=======\par
\par
class \u-26530?\u21029?\u21517?\par
\{\par
    \u-26530?\u21029?\u20839?\u23481?\par
\};\par
\par
\par
\par
\u-29497?\u26009?\u23553?\u-30499?\par
=======\par
private \u31169?\u26377?\par
\par
public \u20844?\u29992?\par
\par
}
      =                           class1  ( д║│бл┼зi)╝  {\rtf1\ansi\ansicpg1252\deff0{\fonttbl{\f0\fnil\fcharset0 Verdana;}}
{\*\generator Riched20 5.40.11.2210;}\viewkind4\uc1\pard\lang1033\f0\fs20 /*\par
Filename ::        class1.c\par
compile  :: g++ -Wno-deprecated -oclass1  class1.cpp   \par
\par
\u30446?\u30340? :: \par
\u26085?\u26399? :: 3/25 2003\par
*/\par
\par
#include <iostream.h>\par
\par
 class Person          //\u-26530?\u21029?Person\u23459?\u21578?\par
 \{\par
\tab private:                  //\u31169?\u26377?\u-29497?\u26009?\u25104?\u21729??\par
\tab   char *name;\par
\tab   int age;\par
\tab   long int tel;\par
\par
\tab public:             //\u20844?\u29992?\u20989?\u25976?\u25104?\u21729?\par
\tab   void init_data()     //\u21021?\u20540?\u-30163?\u23450?\par
\tab\tab\{\par
\tab\tab\tab name="Ed";\par
\tab\tab\tab age=5;\par
\tab\tab\tab tel=2120001l;\par
\tab\tab\}\tab\par
\tab   void printdata()      //\u-26513?\u31034?\u-244?\u-31147?\u29702?\par
      \{\par
\tab\tab\tab cout << "The boy is " << name <<"\\n"\par
\tab\tab\tab\tab   << "Age = " << age <<"\\n"\par
\tab\tab\tab\tab   << "Tel = " << tel <<"\\n";\par
\tab\tab\}\par
 \};\par
\par
\par
 int main(void)\par
 \{\par
\tab Person p1;   //\u32080?\u27083?\u-25900?\u-29814?\u25976?\u23450?\u32681??\par
\par
\tab p1.init_data();     //\u21021?\u20540?\u-30163?\u23450?\par
\tab p1.printdata();     //\u-26513?\u31034?\u-244?\u-31147?\u29702?\par
\tab return (0);\par
 \}\par
\par
}
      =                           class1  ( е~│бл┼зi)  {\rtf1\ansi\ansicpg1252\deff0{\fonttbl{\f0\fnil\fcharset0 Verdana;}}
{\*\generator Riched20 5.40.11.2210;}\viewkind4\uc1\pard\lang1033\f0\fs20 /*\par
Filename ::        class1.c\par
compile  :: g++ -Wno-deprecated -oclass2  class2.cpp   \par
\par
Auther : Jing-Wen.Lai\par
\u30446?\u30340? :: \par
\u26085?\u26399? :: 3/25 2003\par
*/\par
#include <iostream.h>\par
\par
 class Person          //\u-26530?\u21029?Person\u23459?\u21578?\par
 \{\par
\tab private:                  //\u31169?\u26377?\u-29497?\u26009?\u25104?\u21729??\par
\tab   char *name;\par
\tab   int age;\par
\tab   long int tel;\par
\par
\tab public:                   //\u20844?\u29992?\u20989?\u25976?\u25104?\u21729?\par
\tab   void init_data();     //\u21021?\u20540?\u-30163?\u23450?\par
\tab   void printdata();      //\u-26513?\u31034?\u-244?\u-31147?\u29702?\par
 \};\par
\par
 int main()\par
 \{\par
\tab Person p1;   //\u32080?\u27083?\u-25900?\u-29814?\u25976?\u23450?\u32681??\par
\par
\tab p1.init_data();     //\u21021?\u20540?\u-30163?\u23450??\par
\tab p1.printdata();     //\u-26513?\u31034?\u-244?\u-31147?\u29702?\par
\par
\tab return (0);\par
 \}\par
\par
 void Person::init_data()     //\u21021?\u20540?\u-30163?\u23450?\par
 \{\par
  name="Ed";\par
  age=5;\par
  tel=2120001l;\par
 \}\par
\par
 void Person::printdata()      //\u-26513?\u31034?\u-244?\u-31147?\u29702?\par
 \{\par
  cout << "The boy is " << name <<"\\n"\par
\tab\tab  << "Age = " << age<<"\\n"\par
\tab\tab  << "Tel = " << tel<<endl;\par
 \}\par
}
      =                           hello_qt√  {\rtf1\ansi\deff0{\fonttbl{\f0\fnil\fcharset0 Verdana;}}
{\colortbl ;\red0\green0\blue255;}
{\*\generator Riched20 5.40.11.2210;}\viewkind4\uc1\pard\lang1033\f0\fs20 /*\par
Filename ::       hello_qt.cpp\par
compile command : g++ -I$QTDIR/include -L$QTDIR/lib -lqt -o hello_qt hello_qt.cpp\par
execute command : ./hello_qt& ( \u19999?\u21040?\u-32564?\u26223?\u22519?\u-30644? )\par
\par
\u30446?\u30340? :: Linux GUI \u-30314?\u31383?\u31243?\u24335? \u30340?\u22522?\u26412?\u28204?\u-30106?\u-244?\u24314?\u31435?\u19968?\u20491? Hello QT! \u30340?\u22522?\u26412?\u-30314?\u31383? \u12290? \par
\u21443?\u-32765? :  {\field{\*\fldinst{HYPERLINK "http://doc.trolltech.com/3.1/tutorial1-01.html"}}{\fldrslt{\ul\cf1 http://doc.trolltech.com/3.1/tutorial1-01.html}}}\f0\fs20                                                                                                      \par
\u26085?\u26399? :: 3/23 2003\par
*/\par
\par
#include <qapplication.h>\par
#include <qpushbutton.h>\par
\par
int main( int argc, char **argv )\{\par
    QApplication a( argc, argv );\par
\par
    QPushButton hello( "Hello QT!", 0 );\par
    hello.resize( 100, 30 );\par
\par
    a.setMainWidget( &hello );\par
    hello.show();\par
    return a.exec();\par
\}\par
}
      =                           qt_quitД  {\rtf1\ansi\deff0{\fonttbl{\f0\fnil\fcharset0 Verdana;}}
{\colortbl ;\red0\green0\blue255;}
{\*\generator Riched20 5.40.11.2210;}\viewkind4\uc1\pard\lang1033\f0\fs20 /*\par
Filename ::       qt_quit.cpp\par
compile command : g++ -I$QTDIR/include -L$QTDIR/lib -lqt -o qt_quit qt_quit.cpp\par
execute command : ./qt_quit& ( \u19999?\u21040?\u-32564?\u26223?\u22519?\u-30644? )\par
\par
\u30446?\u30340? :: Linux GUI \u-30314?\u31383?\u31243?\u24335? \u30340?\u22522?\u26412?\u28204?\u-30106?\u-244?\u21487?\u20197?\u-31147?\u29702?\u20107?\u20214?\u30340?\u20659?\u-28578? \u12290? \par
\u21443?\u-32765? :  {\field{\*\fldinst{HYPERLINK "http://doc.trolltech.com/3.1/tutorial1-02.html"}}{\fldrslt{\ul\cf1 http://doc.trolltech.com/3.1/tutorial1-02.html}}}\f0\fs20                                                                                                    \par
\u26085?\u26399? :: 3/23 2003\par
*/\par
#include <qapplication.h>\par
#include <qpushbutton.h>\par
#include <qfont.h>\par
\par
int main( int argc, char **argv )\par
\{\par
    QApplication a( argc, argv );\par
\par
    QPushButton quit( "Quit", 0 );\par
    quit.resize( 75, 30 );\par
    quit.setFont( QFont( "Times", 18, QFont::Bold ) );\par
\par
    QObject::connect( &quit, SIGNAL(clicked()), &a, SLOT(quit()) );\par
\par
    a.setMainWidget( &quit );\par
    quit.show();\par
    return a.exec();\par
\}\par
}
      =                           qt_slotы  {\rtf1\ansi\deff0{\fonttbl{\f0\fnil\fcharset0 Verdana;}}
{\*\generator Riched20 5.40.11.2210;}\viewkind4\uc1\pard\lang1033\f0\fs20\u25688?\u-27900?\u26044? , QT \u31243?\u24335?\u-30163?\u-30200? \u-244?O'reilly  p32\par
=========================\par
\par
class MyClass : public Qobject\par
\{\par
Q_OBJECT\par
...\par
signals:\par
\tab // \u23559?\u20320?\u30340?\u-30198?\u-31137?\u25918?\u22312?\u-28647?\u-30495?,\u22914?\par
\tab void somethingDone();\par
...\par
public slots:\par
\tab // \u23559?\u20320?\u20844?\u-27253?\u30340?\u28317?\u27133?\u25918?\u22312?\u-28647?\u-30495?,\u22914?\par
\tab viod soltDoSomething();\par
\par
private slots:\par
\tab // \u23559?\u20320?\u31169?\u26377?\u30340?\u28317?\u27133?\u25918?\u22312?\u-28647?\u-30495?,\u22914?\par
\tab void slotDoSomethingInternal();\par
\par
\tab // \u30070?\u28982?, \u20320?\u21487?\u20197?\u21152?\u20837?\u20854?\u20182?\u30340?\u23459?\u21578?\par
\}\par
\par
================================\par
}
      =                           иSе╬к║  {\rtf1\ansi\deff0{\fonttbl{\f0\fnil\fcharset0 Verdana;}}
{\colortbl ;\red0\green0\blue255;}
{\*\generator Riched20 5.40.11.2210;}\viewkind4\uc1\pard\lang1033\f0\fs20 ttyiofunctions : Linux Keyboard Interrupts for Pascal, C, and C++.\par
{\field{\*\fldinst{HYPERLINK "http://www.mathcs.carleton.edu/courses/course_resources/cs117/tty-io-functions.html"}}{\fldrslt{\ul\cf1 http://www.mathcs.carleton.edu/courses/course_resources/cs117/tty-io-functions.html}}}\f0\fs20\par
Advanced C Programming for Displays\par
{\field{\*\fldinst{HYPERLINK "http://www.basepath.com/aup/BookSoftware/"}}{\fldrslt{\ul\cf1 http://www.basepath.com/aup/BookSoftware/}}}\f0\fs20\par
\par
{\field{\*\fldinst{HYPERLINK "http://vig.prenhall.com/"}}{\fldrslt{\ul\cf1 http://vig.prenhall.com/}}}\f0\fs20\par
}
      =                  А        │цп┬к║Ї  {\rtf1\ansi\deff0{\fonttbl{\f0\fnil\fcharset0 Verdana;}}
{\*\generator Riched20 5.40.11.2210;}\viewkind4\uc1\pard\lang1033\f0\fs20 /*\par
\par
Filename ::        \par
compile command :  \par
\par
\u30446?\u30340? ::  \u12290? \par
\u21443?\u-32765? :: \u12290?\par
\u26085?\u26399? :: \par
\par
*/\par
#include <iostream.h>\par
#include <stdio.h>\par
#include <termios.h>\par
#include <unistd.h>\par
#include <sys/io.h>\par
\par
\par
#define CCW 0x303  /* 8255 CCW */\par
#define PA 0x300   /* 8255 PORT A */\par
\par
class ClassFor8255Card          //\u-26530?\u21029?Person\u23459?\u21578?\par
 \{\par
\tab public:                 \par
\tab   int initAndApplySystemAddrFor8255Card();\tab\tab // \u21521?\u31995?\u32113?\u30003?\u-30005? 8255\u21345?\u25152?\u-26880?\u30340?\u20301?\u32622?\par
\tab   int releaseSystemAddrFor8255Card();\tab\tab\tab // \u23559? 8255\u21345?\u25152?\u-26880?\u30340?\u20301?\u32622?\u-28540?\u32102?\u31995?\u32113?\par
\tab   void brightAllLedOn8255Card();\tab\tab\tab\tab // \u-24866?\u20142? 8255\u21345?\u19978?\u30340? LED\par
\tab   void darkAllLedOn8255Card();\tab\tab\tab\tab\tab // \u29060?\u25481? 8255\u21345?\u19978?\u30340? LED  \par
 \};\par
\par
\par
int main()\par
\{\par
  \par
  int ch =0;          /*  \u-27787?\u30436?\u25152?\u25353?\u19979?\u30340?\u23383?\u20803? */\par
\par
  ClassFor8255Card pio8255Card;   //\u32080?\u27083?\u-25900?\u-29814?\u25976?\u23450?\u32681??\par
  \par
  while(ch!=4)\{\par
\tab cout  <<"1:\u21021?\u22987?\u21270? 2:LED\u20840?\u20142? 3:LED\u20840?\u26263? 4:\u-26910?\u-27253?\\n";\par
\tab cin>>ch;\par
\tab cout<<"Selected Function is :"<<ch<<"\\n";\par
\tab\par
\tab switch(ch)\{\par
\tab     case 1:\par
\tab\tab\par
\tab\tab\tab\tab     \par
\tab\tab pio8255Card.initAndApplySystemAddrFor8255Card();\par
\tab\tab   break;\par
\tab\tab case 2:\par
\tab\tab\tab\par
\tab\tab\tab pio8255Card.brightAllLedOn8255Card();\par
\tab\tab   break;\par
\tab\tab case 3:\par
\tab\tab\tab\par
\tab\tab\tab pio8255Card.darkAllLedOn8255Card();\par
\tab\tab   break;\par
\tab\tab case 4:\par
\tab\tab\tab\par
\tab\tab\tab pio8255Card.releaseSystemAddrFor8255Card();\par
\tab\tab   break;\par
\tab\tab default:\par
\tab\tab\tab cout << "undefine Function ,try again please!\\n" ;\par
\tab\tab   break;\par
\tab\}\par
    \par
  \}\par
  return (0); \par
\}\par
\par
int ClassFor8255Card::initAndApplySystemAddrFor8255Card()     //\u21021?\u20540?\u-30163?\u23450?\par
 \{\par
  cout << "initAndApplySystemAddrFor8255Card\\n";\par
\par
  /* \u21462?\u24471?\u22496?\u20301?\u22336?\u30340?\u23384?\u21462?\u27402?\u-27056? */\par
   if (ioperm(CCW, 3, 1)) \{perror("ioperm"); return (0);\}\par
   if (ioperm(PA, 3, 1))  \{perror("ioperm"); return (0);\}\par
\par
   /* \u23450?\u32681? 8255 \u24037?\u20316?\u27169?\u24335? */\par
   outb(0x80, CCW);\par
\par
   /* \u-28211?\u32622? 8255 PORT A \u30340?\u-28872?\u20986?\u-29497?\u26009?\u20449?\u-31137? (D0-7) \u20840?\u28858?\u-26890? (0) */\par
   outb(0, PA);\par
\tab\par
 \}\par
\par
void ClassFor8255Card::brightAllLedOn8255Card()    \par
 \{\par
  cout << "brightAllLedOn8255Card\\n";\par
  outb( 0xff, PA);\par
  \par
 \}\par
void ClassFor8255Card::darkAllLedOn8255Card()  \par
 \{\par
  cout << "darkAllLedOn8255Card\\n";\par
  outb( 0x00, PA);\par
 \}\par
int ClassFor8255Card::releaseSystemAddrFor8255Card()   \par
 \{\par
  cout << "releaseSystemAddrFor8255Card\\n";\par
  //  LED \u19981?\u20142? \par
  outb( 0x00, PA);\par
\par
  /* \u25105?\u20497?\u19981?\u20877?\u-26880?\u-30335?\u-28647?\u20123?\u22496?\u20301?\u22336? */\par
  if (ioperm(CCW, 3, 0)) \{perror("ioperm"); return (0);\}\par
  if (ioperm(PA, 3, 0))  \{perror("ioperm"); return (0);\}\par
\par
 \}\par
}
      =                А        2┤  {\rtf1\ansi\deff0{\fonttbl{\f0\fnil\fcharset0 Verdana;}}
{\*\generator Riched20 5.40.11.2210;}\viewkind4\uc1\pard\lang1033\f0\fs20 /*\par
\par
Filename ::        \par
compile command :  \par
\par
\u30446?\u30340? ::  \u12290? \par
\u21443?\u-32765? :: \u12290?\par
\u26085?\u26399? :: \par
\par
*/\par
#include <iostream.h>\par
#include <stdio.h>\par
#include <termios.h>\par
#include <unistd.h>\par
#include <sys/io.h>\par
\par
\par
#define CCW 0x303  /* 8255 CCW */\par
#define PA 0x300   /* 8255 PORT A */\par
\par
class ClassForPio8255Card          //\u-26530?\u21029?Person\u23459?\u21578?\par
 \{\par
\tab private: \par
\tab\tab int pio8255CardPort_A_Data;\par
\par
\tab public:                 \par
\tab   \par
\tab   int initAndApplySystemAddrFor8255Card();\tab\tab // \u21521?\u31995?\u32113?\u30003?\u-30005? 8255\u21345?\u25152?\u-26880?\u30340?\u20301?\u32622?\par
\tab   int releaseSystemAddrFor8255Card();\tab\tab\tab // \u23559? 8255\u21345?\u25152?\u-26880?\u30340?\u20301?\u32622?\u-28540?\u32102?\u31995?\u32113?\par
\tab   void piliLampFromMSBtoLSB();\tab\tab\tab\tab\tab // 8255\u21345?\u19978?\u30340?LED \u26371?\u30001?\u-25896?\u20301?\u20803?\u-24866?\u20142?\u21040?\u20302?\u20301?\u20803?\par
\tab   void piliLampFromLSBtoMSB();\tab\tab\tab\tab\tab // 8255\u21345?\u19978?\u30340?LED \u26371?\u30001?\u20302?\u20301?\u20803?\u-24866?\u20142?\u21040?\u-25896?\u20301?\u20803? \par
\tab   void CypiliLampFromLSBtoMSB();\tab\par
\tab   void brightAllLedOn8255Card();\tab\tab\tab\tab // \u-24866?\u20142? 8255\u21345?\u19978?\u30340? LED\par
\tab   void darkAllLedOn8255Card();\tab\tab\tab\tab\tab // \u29060?\u25481? 8255\u21345?\u19978?\u30340? LED  \par
 \};\par
\par
\par
int main()\par
\{\par
  \par
  int ch =0;          /*  \u-27787?\u30436?\u25152?\u25353?\u19979?\u30340?\u23383?\u20803? */\par
\par
  ClassForPio8255Card pio8255Card;   //\u32080?\u27083?\u-25900?\u-29814?\u25976?\u23450?\u32681??\par
  \par
  pio8255Card.initAndApplySystemAddrFor8255Card();\par
\par
  while(ch!=5)\{\par
\tab cout  <<"1:LED\u30001?\u-25896?\u20301?\u20803?\u-24866?\u20142?\u21040?\u20302?\u20301?\u20803? 2:LED\u20840?\u20142? 3:LED\u20840?\u26263? 5:LED\u30001?\u20302?\u20301?\u20803?\u-24866?\u20142?\u21040?\u-25896?\u20301?\u20803?\\n";\par
\tab cin>>ch;\par
\tab cout<<"Selected Function is :"<<ch<<"\\n";\par
\tab\par
\tab switch(ch)\{\par
\tab     case 1:\par
\tab\tab\tab pio8255Card.piliLampFromMSBtoLSB();\par
\tab\tab\tab\tab     \par
\tab\tab\par
\tab\tab   break;\par
\tab\tab case 2:\par
\tab\tab\tab\par
\tab\tab\tab pio8255Card.brightAllLedOn8255Card();\par
\tab\tab   break;\par
\tab\tab case 3:\par
\tab\tab\tab\par
\tab\tab\tab pio8255Card.darkAllLedOn8255Card();\par
\tab\tab   break;\par
\tab\tab case 4:\par
\tab\tab\tab pio8255Card.piliLampFromLSBtoMSB();\par
\tab\tab\tab\par
\tab\tab   break;\par
\tab\tab default:\par
\tab\tab\tab cout << "undefine Function ,try again please!\\n" ;\par
\tab\tab   break;\par
\tab\}\par
    \par
  \}\par
  pio8255Card.releaseSystemAddrFor8255Card();\par
  return (0); \par
\}\par
\par
int ClassForPio8255Card::initAndApplySystemAddrFor8255Card()\{\par
  cout << "initAndApplySystemAddrFor8255Card\\n";\par
\par
  /* \u21462?\u24471?\u22496?\u20301?\u22336?\u30340?\u23384?\u21462?\u27402?\u-27056? */\par
   if (ioperm(CCW, 3, 1)) \{perror("ioperm"); return (0);\}\par
   if (ioperm(PA, 3, 1))  \{perror("ioperm"); return (0);\}\par
\par
   /* \u23450?\u32681? 8255 \u24037?\u20316?\u27169?\u24335? */\par
   outb(0x80, CCW);\par
\par
   /* \u-28211?\u32622? 8255 PORT A \u30340?\u-28872?\u20986?\u-29497?\u26009?\u20449?\u-31137? (D0-7) \u20840?\u28858?\u-26890? (0) */\par
   outb(0, PA);\par
\tab\par
 \}\par
\par
void ClassForPio8255Card::brightAllLedOn8255Card()\{\par
  cout << "brightAllLedOn8255Card\\n";\par
  outb( 0xff, PA);\par
  \par
 \}\par
void ClassForPio8255Card::darkAllLedOn8255Card()\{\par
  cout << "darkAllLedOn8255Card\\n";\par
  outb( 0x00, PA);\par
 \}\par
void ClassForPio8255Card::piliLampFromLSBtoMSB()\{\par
  pio8255CardPort_A_Data=0x01;\par
  for(int i=0; i<8; i++)\{\par
\tab outb( pio8255CardPort_A_Data, PA);\par
\tab usleep(1000000);\par
\tab pio8255CardPort_A_Data*=2;\par
  \}\par
  \par
\par
\}\par
\par
void ClassForPio8255Card::piliLampFromMSBtoLSB()\{\par
\tab pio8255CardPort_A_Data=0x80;\par
\tab for(int i=0; i<8; i++)\{\par
\tab\tab outb( pio8255CardPort_A_Data, PA);\par
\tab\tab usleep(1000000);\par
\tab\tab pio8255CardPort_A_Data/=2;\par
\tab\}\par
\}\par
\par
int ClassForPio8255Card::releaseSystemAddrFor8255Card()\{\par
  cout << "releaseSystemAddrFor8255Card\\n";\par
  //  LED \u19981?\u20142? \par
  outb( 0x00, PA);\par
\par
  /* \u25105?\u20497?\u19981?\u20877?\u-26880?\u-30335?\u-28647?\u20123?\u22496?\u20301?\u22336? */\par
  if (ioperm(CCW, 3, 0)) \{perror("ioperm"); return (0);\}\par
  if (ioperm(PA, 3, 0))  \{perror("ioperm"); return (0);\}\par
\par
 \}\par
}
      =                А        3 (╡Lкkе[дJkeyboardк║дд┬_)	  {\rtf1\ansi\deff0{\fonttbl{\f0\fnil\fcharset0 Verdana;}}
{\*\generator Riched20 5.40.11.2210;}\viewkind4\uc1\pard\lang1033\f0\fs20 /*\par
\par
Filename ::        \par
compile command :  \par
\par
\u30446?\u30340? ::  \u12290? \par
\u21443?\u-32765? :: \u12290?\par
\u26085?\u26399? :: \par
\par
*/\par
#include <iostream.h>\par
#include <stdio.h>\par
#include <termios.h>\par
#include <unistd.h>\par
#include <sys/io.h>\par
\par
\par
#define CCW 0x303  /* 8255 CCW */\par
#define PA 0x300   /* 8255 PORT A */\par
\par
\par
\par
int ch =0;          /*  \u-27787?\u30436?\u25152?\u25353?\u19979?\u30340?\u23383?\u20803? */\par
\par
class ClassForPio8255Card          //\u-26530?\u21029?Person\u23459?\u21578?\par
 \{\par
\tab private: \par
\tab\tab int pio8255CardPort_A_Data;\par
\tab\tab static struct termios orig, neww;\par
\tab\tab static int peek = -1;\par
\par
\tab\tab tcgetattr(0, &orig);\par
\tab\tab neww = orig; neww.c_lflag &= ~ICANON; neww.c_lflag &= ~ECHO; neww.c_lflag &= ~ISIG;\par
\tab\tab neww.c_cc[VMIN] = 1; neww.c_cc[VTIME] = 0; tcsetattr(0, TCSANOW, &neww);\par
\par
\tab public:                 \par
\tab   \par
\tab   int initAndApplySystemAddrFor8255Card();\tab\tab // \u21521?\u31995?\u32113?\u30003?\u-30005? 8255\u21345?\u25152?\u-26880?\u30340?\u20301?\u32622?\par
\tab   int releaseSystemAddrFor8255Card();\tab\tab\tab // \u23559? 8255\u21345?\u25152?\u-26880?\u30340?\u20301?\u32622?\u-28540?\u32102?\u31995?\u32113?\par
\tab   void piliLampFromMSBtoLSB();\tab\tab\tab\tab\tab // 8255\u21345?\u19978?\u30340?LED \u26371?\u30001?\u-25896?\u20301?\u20803?\u-24866?\u20142?\u21040?\u20302?\u20301?\u20803?\par
\tab   void piliLampFromLSBtoMSB();\tab\tab\tab\tab\tab // 8255\u21345?\u19978?\u30340?LED \u26371?\u30001?\u20302?\u20301?\u20803?\u-24866?\u20142?\u21040?\u-25896?\u20301?\u20803? \par
\tab   void CyclingPiliLampFromLSBtoMSB_untilKeyboardPressAnyKey();\tab\par
\tab   void CyclingPiliLampFromMSBtoLSB_untilKeyboardPressAnyKey();\par
\tab   void brightAllLedOn8255Card();\tab\tab\tab\tab // \u-24866?\u20142? 8255\u21345?\u19978?\u30340? LED\par
\tab   void darkAllLedOn8255Card();\tab\tab\tab\tab\tab // \u29060?\u25481? 8255\u21345?\u19978?\u30340? LED  \par
 \};\par
\par
\par
int main()\par
\{\par
  \par
  \par
\par
  ClassForPio8255Card pio8255Card;   //\u32080?\u27083?\u-25900?\u-29814?\u25976?\u23450?\u32681??\par
  \par
  pio8255Card.initAndApplySystemAddrFor8255Card();\par
\par
  while(ch!=7)\{\par
\tab cout  <<"1:LED\u30001?\u-25896?\u20301?\u20803?\u-24866?\u20142?\u21040?\u20302?\u20301?\u20803? 2:LED\u20840?\u20142? 3:LED\u20840?\u26263? 5:LED\u30001?\u20302?\u20301?\u20803?\u-24866?\u20142?\u21040?\u-25896?\u20301?\u20803?\\n";\par
\tab cin>>ch;\par
\tab cout<<"Selected Function is :"<<ch<<"\\n";\par
\tab\par
\tab switch(ch)\{\par
\tab     case 1:\par
\tab\tab\tab pio8255Card.piliLampFromMSBtoLSB();\par
\tab\tab\tab\tab     \par
\tab\tab\par
\tab\tab   break;\par
\tab\tab case 2:\par
\tab\tab\tab\par
\tab\tab\tab pio8255Card.brightAllLedOn8255Card();\par
\tab\tab   break;\par
\tab\tab case 3:\par
\tab\tab\tab\par
\tab\tab\tab pio8255Card.darkAllLedOn8255Card();\par
\tab\tab   break;\par
\tab\tab case 4:\par
\tab\tab\tab pio8255Card.piliLampFromLSBtoMSB();\par
\tab\tab\tab\par
\tab\tab   break;\par
\tab\tab case 5:\par
\tab\tab\tab CyclingPiliLampFromLSBtoMSB_untilKeyboardPressAnyKey();\par
\tab\tab\tab\par
\tab\tab   break;\par
\tab\tab case 6:\par
\tab\tab\tab CyclingPiliLampFromMSBtoLSB_untilKeyboardPressAnyKey();\par
\tab\tab\tab\par
\tab\tab   break;\par
\par
\tab\tab default:\par
\tab\tab\tab cout << "undefine Function ,try again please!\\n" ;\par
\tab\tab   break;\par
\tab\}\par
    \par
  \}\par
  pio8255Card.releaseSystemAddrFor8255Card();\par
  tcsetattr(0,TCSANOW, &orig);\par
  return (0); \par
\}\par
\par
int ClassForPio8255Card::initAndApplySystemAddrFor8255Card()\{\par
  cout << "initAndApplySystemAddrFor8255Card\\n";\par
\par
  /* \u21462?\u24471?\u22496?\u20301?\u22336?\u30340?\u23384?\u21462?\u27402?\u-27056? */\par
   if (ioperm(CCW, 3, 1)) \{perror("ioperm"); return (0);\}\par
   if (ioperm(PA, 3, 1))  \{perror("ioperm"); return (0);\}\par
\par
   /* \u23450?\u32681? 8255 \u24037?\u20316?\u27169?\u24335? */\par
   outb(0x80, CCW);\par
\par
   /* \u-28211?\u32622? 8255 PORT A \u30340?\u-28872?\u20986?\u-29497?\u26009?\u20449?\u-31137? (D0-7) \u20840?\u28858?\u-26890? (0) */\par
   outb(0, PA);\par
\tab\par
 \}\par
\par
void ClassForPio8255Card::brightAllLedOn8255Card()\{\par
  cout << "brightAllLedOn8255Card\\n";\par
  outb( 0xff, PA);\par
  \par
 \}\par
void ClassForPio8255Card::darkAllLedOn8255Card()\{\par
  cout << "darkAllLedOn8255Card\\n";\par
  outb( 0x00, PA);\par
 \}\par
void ClassForPio8255Card::piliLampFromLSBtoMSB()\{\par
  pio8255CardPort_A_Data=0x01;\par
  for(int i=0; i<8; i++)\{\par
\tab outb( pio8255CardPort_A_Data, PA);\par
\tab usleep(1000000);\par
\tab pio8255CardPort_A_Data*=2;\par
  \}\par
\}\par
void ClassForPio8255Card::CyclingPiliLampFromLSBtoMSB_untilKeyboardPressAnyKey()\{\par
  pio8255CardPort_A_Data=0x01;\par
  while(!kbhit()) \{\par
    for(int i=0; i<8; i++)\{\par
\tab outb( pio8255CardPort_A_Data, PA);\par
\tab usleep(1000000);\par
\tab pio8255CardPort_A_Data*=2;\par
    \par
  \}\par
\}\par
void ClassForPio8255Card::CyclingPiliLampFromMSBtoLSB_untilKeyboardPressAnyKey()\{\par
\tab pio8255CardPort_A_Data=0x80;\par
\tab while(!kbhit()) \{\par
    for(int i=0; i<8; i++)\{\par
\tab\tab outb( pio8255CardPort_A_Data, PA);\par
\tab\tab usleep(1000000);\par
\tab\tab pio8255CardPort_A_Data/=2;\par
    \par
\tab\}\par
\}\par
void ClassForPio8255Card::piliLampFromMSBtoLSB()\{\par
\tab pio8255CardPort_A_Data=0x80;\par
\tab for(int i=0; i<8; i++)\{\par
\tab\tab outb( pio8255CardPort_A_Data, PA);\par
\tab\tab usleep(1000000);\par
\tab\tab pio8255CardPort_A_Data/=2;\par
\tab\}\par
\}\par
\par
int ClassForPio8255Card::releaseSystemAddrFor8255Card()\{\par
  cout << "releaseSystemAddrFor8255Card\\n";\par
  //  LED \u19981?\u20142? \par
  outb( 0x00, PA);\par
\par
  /* \u25105?\u20497?\u19981?\u20877?\u-26880?\u-30335?\u-28647?\u20123?\u22496?\u20301?\u22336? */\par
  if (ioperm(CCW, 3, 0)) \{perror("ioperm"); return (0);\}\par
  if (ioperm(PA, 3, 0))  \{perror("ioperm"); return (0);\}\par
\par
 \}\par
\par
/* ======================= */\par
/*   sub Function          */\par
/* ======================= */\par
int ClassForPio8255Card::kbhit()\par
\{\par
    char ch;int nread;\par
    if(peek != -1) return 1;\par
    neww.c_cc[VMIN]=0;\par
    tcsetattr(0, TCSANOW, &neww);\par
    nread = read(0,&ch,1);\par
    neww.c_cc[VMIN]=1;\par
    tcsetattr(0, TCSANOW, &neww);    \par
\tab if(nread == 1) \{\par
\tab     peek = ch;\par
        return 1;\par
    \}\par
    return 0;\par
\}\par
\par
int ClassForPio8255Card::readch()\par
\{\par
    char ch;\par
    if(peek != -1) \{\par
        ch = peek;\par
        peek = -1;\par
        return ch;\par
    \}\par
    read(0,&ch,1);\par
    return ch;\par
\}\par
}
      =              