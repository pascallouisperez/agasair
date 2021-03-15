\documentclass[letterpaper,12pt,twoside]{article}

\setlength{\oddsidemargin}{0.2in}
\setlength{\evensidemargin}{0.1in}
\setlength{\topmargin}{-22pt}
\setlength{\headsep}{10pt}
\setlength{\textwidth}{450pt}
\setlength{\textheight}{680pt}
\usepackage{2up}
\special{landscape}

\usepackage{fancyhdr}
\pagestyle{fancy}
\fancyfoot{}

\usepackage{multicol}
\usepackage{tikz}
\usepackage{environ}
\usepackage{fancyhdr}
\usepackage{amssymb}
\usepackage{xfrac}
\usepackage{mfirstuc}
\usepackage{gensymb}

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
  \newcommand{\simpleitem}[1]{%
    % TODO: \capitalisewords{##1}, however does not work with math mode.
    ##1\\
  }
  \newcommand{\newsection}[1]{%
    % TODO: \capitalisewords{##1}, however does not work with math mode.
    \vspace{0.1em}\small{\textbf{\textit{\textellipsis\ \uppercase{##1}}}}\\
  }
  \newcommand{\step}[1]{%
    \hspace*{10em}-\hspace*{\labelsep}##1\\
  }
  \noindent
  \begin{tabular}{p{0.95\linewidth}}
       \multicolumn{1}{l}{\large{\textbf{\uppercase{#1}}}}\\
}{\end{tabular}\vspace{0.8em}}

% Various V_speeds
\newcommand{\vfe}[0]{$115$}
\newcommand{\vr}[0]{$52$}
\newcommand{\vy}[0]{$76$}
\newcommand{\vx}[0]{$66$}
\newcommand{\vg}[0]{$69$}
