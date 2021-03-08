\documentclass[11pt]{article}

\usepackage{multicol}
\usepackage{tikz}
\usepackage{environ}
\usepackage{fancyhdr}
\usepackage{amssymb}
\usepackage{xfrac}
\usepackage{mfirstuc}
\usepackage[
  letterpaper,
  top=0.5in,
  headsep=1em,
  marginparwidth=0pt,
  marginpar=0pt,
  lmargin=0.15in,
  rmargin=0.15in,
  footnotesep=1em
]{geometry}

\pagestyle{fancy}
\fancyfoot{}

\renewcommand{\footrulewidth}{0pt}
\setlength{\tabcolsep}{0pt}

% checklist env sets up a table and format the items.
% in case a item has steps use the \step{asdf}
% command.
\newenvironment{checklist}[1]{%
  \renewcommand{\item}[2]{%
    % TODO: \capitalisewords{##1}, however does not work with math mode.
    ##1\hspace{1.5em}\dotfill\makebox{\uppercase{##2}}\\
  }
  \newcommand{\step}[1]{%
    \hspace*{10em}-\hspace*{\labelsep}##1\\
  }
  \noindent
  \begin{tabular}{p{0.95\linewidth}}
       \multicolumn{1}{l}{\textbf{\uppercase{#1}}}\\
}{\end{tabular}\vspace{1em}}