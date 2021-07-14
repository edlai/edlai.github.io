#!/usr/bin/wish -f
#<!-->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> HW 4 <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<-->
#                        A contact manager
# 【Author 】   Jing-Wen.Lai
# 【 ver      】   0.1
# 【 Env.    】    tclPro/wish(直譯器 window shell ;Linux平台 ; 請自行設定 wish 路徑 (程式第一行) )
#                        Window XP/ Red Hat 7.0 (平台)
#                        EditPlus(Editor;可有可無 ; Ms Windows )
#                        Visual Tcl(Editor; 可將 .tcl 轉成 .exe 檔 ;可有可無 ; Ms Windows )
# 【  Exec  】   <<  Window XP  >> after you installed tclPro , double click the hw4.tcl file  
# 【 function 】 基本作業上所說的功能                
#
# 【  未完成.  】menu 的 help 不知如何向右對齊
#                          可依作業所言 改成 pack 的 geometry management   
#
# 【  缺點.  】  Entry 不太會用 有些地方寫的 不是 很好
#
# 【  參考.  】  1. 洪朝貴的首頁 http://www.cyut.edu.tw/~ckhung/
#                        2. tclPro 內部 demo / Demos-IWidgets( 非常有用 )
#                        3. Beginning Linux Programming 基峰 isbn 957-566-692-5
# 【  備註.  】  1. 可以以陣列來精簡 程式碼    
#                        2. 只有一字相同即可搜尋到 ,最好改良成更精確搜尋方式(基本上已和作業要求相符)       
#                            附加檔案. hw4.txt  ( Contact Data ) 
#>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

set keyword ""

# ..............    drawing GUI + geometry management      ..................

set counter 0
foreach i { Forename Surname Telephone Email } {
    set ent($i) ""
    label .l$i  -text "$i" -width 10 -anchor w -font "Helvetica 10"
    entry .e$i -justify "left"  -textvariable ent($i)
    grid  .l$i -row  [ incr counter ] -column 0 -sticky "we"
    grid  .e$i -row  $counter -column 1 -sticky "we"   
}

button .find   -text    "Find"  -background "#FFFF66"  -command search   
entry  .key    -justify "left"  -background "#FFFFCC"  -textvariable keyword       
grid   .find   -row   5 -column 0 -sticky "we"
grid   .key    -row   5 -column 1 -sticky "we"


# ..............      Response      ..............................
# my mistake : when Define global Array  do'nt use "global ent(xxx)" ,but "global ent"

proc search { } {
    global keyword
    global ent   
    set    temp ""
    set    gotIt  0
    set    contactFile [open "hw4.txt" "r"]
    while {[gets $contactFile fred] != -1} {
        if {[ regexp $keyword $fred]} {
            set pars "(\[A-Za-z]+) +(\[A-Za-z]+) +(\[0-9]+) +(\[A-Za-z]+)"
            #set pars "Sam Wales 3377 bcd"  # Cannot work , i do'nt know why?
            regexp $pars $fred temp ent(Forename) ent(Surname) ent(Telephone) ent(Email)           
            set    gotIt  1
            break
        }
    }
    close $contactFile
    if { $gotIt == 0 } {       
        tk_messageBox -message "Sorry!! Cannot find it ." -type ok       
    }   
}
