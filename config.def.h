/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

#define MIN_HEIGHT 8

static int topbar = 1;     /* -b  option; if 0, dmenu appears at bottom     */
static int fuzzy = 1; /* fuzzy match on by default */

/* alpha channel value for transparency */
static const unsigned int alpha = 0xf0;
/* window border thickness */
static unsigned int border_width = 0;
/* centered patch options */
static int centered = 0;                    /* -c option; centers dmenu on screen */
static int min_width = 500;                 /* minimum width when centered */

/* -fn option overrides fonts[0]; default X11 font or font set */
static char font[] = "monospace:size=10";
static const char *fonts[] = {
  font,
  "monospace:size=10"
};

static const char *prompt      = NULL;      /* -p  option; prompt to the left of input field */
static const char *dynamic     = NULL;      /* -dy option; dynamic command to run on input change */

static char normbg[] = "#bbbbbb";
static char normfg[] = "#222222";
static char normhighlightfg[] = "#ffc978";
static char normhighlightbg[] = "#222222";
static char selfg[] = "#eeeeee";
static char selbg[] = "#005577";
static char selhighlightfg[] = "#ffc978";
static char selhighlightbg[] = "#005577";
static char *colors[SchemeLast][2] = {
  /*     fg         bg       */
  [SchemeNorm] = { normfg, normbg },
  [SchemeSel] = { selfg, selbg },
  [SchemeSelHighlight] = { selhighlightfg, selhighlightbg },
  [SchemeNormHighlight] = { normhighlightfg, normhighlightbg },
  [SchemeOut] = { "#000000", "#00ffff" },
};

static unsigned int alphas[SchemeLast][2] = {
  [SchemeNorm] = { OPAQUE, alpha },
  [SchemeSel] = { OPAQUE, alpha },
  [SchemeSelHighlight] = { OPAQUE, alpha },
  [SchemeNormHighlight] = { OPAQUE, alpha },
  [SchemeOut] = { OPAQUE, alpha },
};

/* -l option; if nonzero, dmenu uses vertical list with given number of lines */
static unsigned int lines      = 0;
/* -g option: number of columns to draw if lines is > 0 */
static unsigned int columns    = 0;
/* -h option: sets the height in pixel of the dmenu window */
static unsigned int lineheight = 0;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";

/* configurable Xresources */
ResourceAtom configurable_resources[] = {
  { "font", STRING, &font },
  { "normfg", STRING, &normfg },
  { "normbg", STRING, &normbg },
  { "normhighlightfg", STRING, &normhighlightfg },
  { "normhighlightbg", STRING, &normhighlightbg },
  { "selfg", STRING, &selfg },
  { "selbg", STRING, &selbg },
  { "selhighlightfg", STRING, &selhighlightfg },
  { "selhighlightbg", STRING, &selhighlightbg },
};

unsigned int resource_inventory_size = sizeof(configurable_resources)/sizeof(configurable_resources[0]);