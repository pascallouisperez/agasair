\documentclass[11pt]{article}

\usepackage{multicol}
\usepackage[cm]{fullpage}
\usepackage{tikz}
\usepackage{environ}
\usepackage{fancyhdr}
\usepackage{amssymb}
\usepackage{xfrac}
\usepackage{mfirstuc}

\pagestyle{fancy}
\fancyhead{}
\fancyfoot{}

\renewcommand{\headrulewidth}{0pt}
\renewcommand{\footrulewidth}{0pt}

% creates empty checkboxes to be used as the second
% argument to \item on checklist
\newcommand{\checkbox}{\makebox[3ex][r]{\Large{$\square$}}}

% checklist env sets up a table and format the items.
% in case a item has steps use the \step{asdf}
% command.
\newenvironment{checklist}[1]{%
  \renewcommand{\item}[2]{%
    \capitalisewords{##1}\hspace{1.5em}\dotfill\makebox{\uppercase{##2}}\\
  }
  \newcommand{\step}[1]{%
    \hspace*{10em}-\hspace*{\labelsep}##1\\
  }
  \begin{tabular}{p{0.95\linewidth}}
       \multicolumn{1}{l}{\textbf{\uppercase{#1}}}\\
}{\end{tabular}\vspace{1em}}