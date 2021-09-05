# XeLaTeX

## Prior knowledge

- [Learn_LaTeX_in_30_minutes](https://www.overleaf.com/learn/latex/Learn_LaTeX_in_30_minutes)
- [Latex教學](http://www.cs.nthu.edu.tw/~cherung/teaching/2009cs5321/link/latex.pdf)
- [Software Requirements Specification for Gephi](https://gephi.org/users/gephi_srs_document.pdf)
- [SRS Example - MSU CSE](https://www.cse.msu.edu/~cse435/Handouts/SRSExample-webapp.doc)
## Resource

- [大家來學 LaTeX（LaTeX123）](https://www.overleaf.com/articles/da-jia-lai-xue-latex-latex123/jypmqhfhfbyc)
- [TeXample](https://texample.net/)
  - [A family tree](https://texample.net/tikz/examples/family-tree/)
  - [Sequence diagram](https://texample.net/tikz/examples/sequence-diagram/)
  - A simple Tree
  - Diagram of Android activity life cycle
  - Direction-of-arrival diagram
  - EPC flow charts
  - Easy-maintenance flowchart
  - [Filesystem tree](https://texample.net/tikz/examples/filesystem-tree/)
  - Scenario tree
- Tex stackexcahge
  - [Drawing simple sequence diagram](https://tex.stackexchange.com/questions/207240/drawing-simple-sequence-diagram/209079)
## Editor

- Visual Studio Code with [LaTeX Workshop Extension](https://marketplace.visualstudio.com/items?itemName=James-Yu.latex-workshop) and XeLaTeX
- [Overleaf, Online LaTeX Editor](https://www.overleaf.com/)
- [TexMaker](https://www.xm1math.net/texmaker/) with [MikTex](https://miktex.org/)
- [TeXstudio](https://www.texstudio.org/) with [MikTex](https://miktex.org/)
- [WinEdt](https://www.winedt.com/) with [MikTex](https://miktex.org/)
- [ReqView](https://www.reqview.com/)
## Syntax

### Document class and Preamble

```
\documentclass[12pt, letterpaper]{article}
\usepackage[utf8]{inputenc}
\title{Software Requirements Specifications}
\author{<Writer>\footnote{Software Requirements Specifications}}
\date{\today}

\begin{document}
This IEEE standard suggests the following structure for requirements documents.
\end{document}
```

### Document class and Preamble

- documentclass: article, report, book, slides, letter and scrreprt.
- document class parameter: 10pt, 11pt, 12pt, letterpaper, a4paper, twocolumn.

use [The IEEE standard for requirements documents](https://ifs.host.cs.st-andrews.ac.uk/Books/SE9/Web/Requirements/IEEE-standard.html) as a case.

```
\documentclass[12pt, letterpaper]{article}
\usepackage[utf8]{inputenc}
\title{Software Requirements Specifications}
\author{Someone\footnote{Software Requirements Specifications}}
\date{\today}
\begin{document}
\maketitle

\chapter{Introduction}
  \section{Purpose of the requirements document}
  \section{Scope of the product}
  \section{References}
  \section{Overview of the remainder of the document}
\chapter{General description}
  \section{Product perspective}
  \section{Product functions}
  \section{User characteristics}
  \section{General constraints}
  \section{Assumptions and dependencies}
\chapter{Specific requirements}
\chapter{Appendices}
\chapter{Index}

Hello world, this is \LaTeX.

\end{document}
% comment
```

### Section




### Newline

use `\\`.

```
This is the Newline.\\
```

### Font variance

```
{\it This is italic.}
{\sl This is slant.}
{\bf This is boldface.}
And the default is roman.
```

### Font Size

```
{\tiny tiny} \\
{\small small} \\
{\large large} \\
{\Large Large}
```

### itemize (unordered lists)

```
Lists are easy to create:
\begin{itemize}
  \item List entries start with the \verb|\item| command.
  \item Individual entries are indicated with a black dot, a so-called bullet.
  \item The text in the entries may be of any length.
\end{itemize}

```

### enumerate (ordered lists)

```
Numbered (ordered) lists are easy to create:
\begin{enumerate}
  \item Items are numbered automatically.
  \item The numbers start at 1 with each use of the \texttt{enumerate} environment.
  \item Another entry in the list
\end{enumerate}
```



***Example:***

=== "LaTeX"

``` tex linenums="1""
--8<--
docs/engineer/development/documentation/xelatex/text.tex
--8<--
```

### Image



### Table

```
\begin{tabular}[t]{lll}
\hline
column1 & column2 & column3 \\
\hline
item1 & item2 & item3 \\
itemA & itemB & itemC \\
\hline
\end{tabular} 
```

### Figures

### Flow Chart


=== "LaTeX"

``` tex linenums="1""
--8<--
docs/engineer/development/documentation/xelatex/flow-chart.tex
--8<--
```

### Status Machine

=== "LaTeX"

``` tex linenums="1""
--8<--
docs/engineer/development/documentation/xelatex/statu-machine.tex
--8<--
```

### References

- [830-1984 - IEEE Guide for Software Requirements Specifications](https://ieeexplore.ieee.org/document/741940)
- [1233-1998 - IEEE Guide for Developing System Requirements Specifications](https://ieeexplore.ieee.org/document/278253)

- [SRS-IEEE](https://github.com/jpeisenbarth/SRS-Tex)

https://ifs.host.cs.st-andrews.ac.uk/Books/SE9/Web/Requirements/IEEE-standard.html

- [需求規格書撰寫指引](http://120.105.184.250/lwcheng/SSADM/RUP/RUPSamples/%E9%9C%80%E6%B1%82%E8%A6%8F%E6%A0%BC%E6%9B%B8%E6%92%B0%E5%AF%AB%E6%8C%87%E5%BC%95.doc)

- [拯救人生的軟體需求規格書](https://oberonlai.blog/tw/%E6%8B%AF%E6%95%91%E4%BA%BA%E7%94%9F%E7%9A%84%E8%BB%9F%E9%AB%94%E9%9C%80%E6%B1%82%E8%A6%8F%E6%A0%BC%E6%9B%B8/)

- [How to write technical IT requirements to get what you need](
https://www.udemy.com/course/how-to-write-technical-it-requirements-to-get-what-you-need/?utm_source=adwords&utm_medium=udemyads&utm_campaign=LongTail_la.EN_cc.ROW&utm_content=deal4584&utm_term=_._ag_77879424214_._ad_535397245866_._kw__._de_c_._dm__._pl__._ti_dsa-1007766171552_._li_9040379_._pd__._&matchtype=b&gclid=Cj0KCQjwssyJBhDXARIsAK98ITTai6Sn_CB8dkXjO-t9qV8NifuKh9vbq7IX1LdvJQskzOEN_grVjZoaAklZEALw_wcB)

- [TeX Users Group](http://tug.org/)

