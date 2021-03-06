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
  \begin{tabular}{p{\linewidth}}
       \multicolumn{1}{l}{\textbf{\uppercase{#1}}}\\
}{\end{tabular}\vspace{0.8em}}

% phraseology env sets up a table to present exchanges between pilots and ATC
% (or appropriate counter-party, possibly even a broadcast in the case of CTAF).
\newenvironment{phraseology}[1]{%
    \newcommand{\pilotsays}[1]{%
        \multicolumn{2}{p{0.8\linewidth}}{##1\vspace{0.5em}}&\ \\
    }
    \newcommand{\othersays}[1]{%
        \ &\multicolumn{2}{p{0.8\linewidth}}{\textit{##1}\vspace{0.5em}}\\
    }
    \noindent
    \begin{tabular}{p{0.15\linewidth} p{0.65\linewidth} p{0.15\linewidth}}
        \multicolumn{3}{l}{\large{\textbf{\uppercase{#1}}}}\\
}{\end{tabular}\vspace{0.8em}}
