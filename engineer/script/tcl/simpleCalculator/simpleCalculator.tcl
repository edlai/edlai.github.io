#!/usr/bin/wish -f
#
# A Simple calculator (advanced)
#
# % Author        %  Jing-Wen.Lai
# % Version       %  0.1
# % Requirement   %  1. TclPro(直譯器 ; from : http://www.activeperl.com/Products/TclPro/ )
#                    2. Windows XP(平台)
#                    3. Visual Tcl(Editor; 可將 .tcl 轉成 .exe 檔 ;可有可無)
# % Execution     %  after you installed tclPro , double click the .tcl file
# % Function      %  1. 基本作業上所說的功能
#                    2. 除 0 錯誤可偵測出
#                    3. 基本 錯誤 可轉向 至 對話盒 顯示
#
# % Undone.       %  1. 科學符號 E 的功能 還未寫 需看是否可經 函式 直接轉換
#                    2. Entry 輸入字串長度控制
#    
# % Disadvantages %  Entry 不太會用 有些地方寫的 不是 很好
#
# % Reference     %  1. 洪朝貴的首頁 http://www.cyut.edu.tw/~ckhung/
#                    2. tclPro 內部 demo / Demos-IWidgets( 非常有用 )
#                    3. Beginning Linux Programming 基峰 isbn 957-566-692-5


set answer ""
set temp   ""

#  ...............    Drawing GUI    ...........................
#  my mistakes: there is more than one space between -text and "

option add *off.width 10
option add *ent.width 45
button .off -text "OFF"    -background "#FFFF99"  -borderwidth "3" -command {exit}
entry  .ent -justify "right" -textvariable answer

foreach i {1 2 3 4 5 6 7 8 9 0 } {
    button .f$i -text "$i" -command [list AddChar $i]
    if { $i == "0" } {
        grid .f$i -row 4 -column 0 -sticky "ew"
    } else {      
        grid .f$i -row    [expr {(($i%3) != 0 ) ? (($i/3)+1) : ($i/3)}] \
        -column [expr {(($i%3) == 0 ) ? (($i%3)+2) : ($i%3)-1}] -sticky "ew"
    }
}

button .fdot -text "."  -command [list AddChar .]
button .fe   -text "E"  -command [list AddChar E]
button .frightBrackets -text "(" -command [list AddChar (]
button .fleftBrackets  -text ")" -command [list AddChar )]
button .fclr  -text "C"  -background "#CCFF66" -borderwidth "3" -command Clear
button .fequ  -text "="  -background "#33CCFF" -borderwidth "3" -command Evaluate
button .fadd -text "+" -command [list AddChar +]
button .fsub -text "-" -command [list AddChar -]
button .fmul -text "*" -command [list AddChar *]
button .fdiv -text "/" -command [list AddChar /]


# ............   Geometry Management (else 0-9 )   ..................

grid .off -row 0 -column 0 -sticky "ew"
grid .ent -row 0 -column 1 -columnspan 4 -sticky "ew"
grid .fdot -row 4 -column 1 -sticky "ew"
grid .fe   -row 4 -column 2 -sticky "ew"
grid .frightBrackets -row 1 -column 3 -sticky "ew"
grid .fleftBrackets  -row 2 -column 3 -sticky "ew"
grid .fclr -row 3 -column 3 -sticky "ew"
grid .fequ -row 4 -column 3 -sticky "ew"
grid .fadd -row 1 -column 4 -sticky "ew"
grid .fsub -row 2 -column 4 -sticky "ew"
grid .fmul -row 3 -column 4 -sticky "ew"
grid .fdiv -row 4 -column 4 -sticky "ew"

#......................................................................
# response
# my mistakes  : prog  xxx { yyy } {   be care yyy was capsuled by { }
# .....................................................................
# after < 0-9 + - * / ( ) > buttoms is pressed  , display them on display area
proc AddChar { i } {
    .ent insert [.ent index end] $i      
}

# .....   Clear display area   .....
proc Clear { } {          
    .ent delete 0 end
}

# .....   Display the result   .....
proc Evaluate { } {
    global answer  
    global temp
    set temp $answer
    if [ catch { set temp [expr $temp]} res ] {      
        set i [tk_dialog .info "Info" $res info O Ok ]
        set temp ""      
    }  
    .ent delete 0 end
    .ent insert 0 $temp  
}
