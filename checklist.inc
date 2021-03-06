\documentclass[11pt]{article}

\usepackage{multicol}
\usepackage[cm]{fullpage}
\usepackage{tikz}
\usepackage{environ}
\usepackage{fancyhdr}
\usepackage{amssymb}

\pagestyle{fancy}
\fancyhead{}
\fancyfoot{}
\renewcommand{\headrulewidth}{0pt}
\renewcommand{\footrulewidth}{0pt}

% creates empty checkboxes to be used as the second
% argument to \item on checklist
\newcommand{\checkbox}{\makebox[3ex][r]{\Large{$\square$}}}

% draws a dashed box around to group checklists
% a task has a title, which is the group title
\NewEnviron{task}[1]{\par
\begin{tikzpicture}
\node[rectangle,minimum width=0.9\linewidth] (m)
  {\begin{minipage}{0.85\linewidth}
    \begin{center}\uppercase{#1}\\\vspace{1em}\BODY\end{center}
   \end{minipage}};
\draw[dashed](m.south west) rectangle (m.north east);
\end{tikzpicture}\vspace{1em}
}

% checklist env sets up a table and format the items.
% in case a item has steps use the \step{asdf}
% command.
\newenvironment{checklist}[1]{%
  \renewcommand{\item}[2]{%
    ##1\hspace{2em}\dotfill\makebox{\uppercase{##2}}\\
  }
  \newcommand{\step}[1]{%
    \hspace*{10em}-\hspace*{\labelsep}##1\\
  }
  \begin{tabular}{p{0.8\linewidth}}
       \multicolumn{1}{l}{\textbf{\uppercase{#1}}}\\
}{\end{tabular}\vspace{1em}}