#include <X11/Xresource.h>

void
readxresources(void)
{
	XrmInitialize();

	char* xrm;
	if ((xrm = XResourceManagerString(drw->dpy))) {
		char *type;
		XrmDatabase xdb = XrmGetStringDatabase(xrm);
		XrmValue xval;

		if (XrmGetResource(xdb, "dmenu.font", "*", &type, &xval))
			#if PANGO_PATCH
			strcpy(font, xval.addr);
			#else
			fonts[0] = strdup(xval.addr);
			#endif // PANGO_PATCH
		#if !PANGO_PATCH
		else
			fonts[0] = strdup(fonts[0]);
		#endif // PANGO_PATCH
		if (XrmGetResource(xdb, "dmenu.background", "*", &type, &xval))
			colors[SchemeNorm][ColBg] = strdup(xval.addr);
		if (XrmGetResource(xdb, "dmenu.foreground", "*", &type, &xval))
			colors[SchemeNorm][ColFg] = strdup(xval.addr);
		if (XrmGetResource(xdb, "color14", "*", &type, &xval))
			colors[SchemeSel][ColBg] = strdup(xval.addr);
		if (XrmGetResource(xdb, "color0", "*", &type, &xval))
			colors[SchemeSel][ColFg] = strdup(xval.addr);
		if (XrmGetResource(xdb, "dmenu.outbackground", "*", &type, &xval))
			colors[SchemeOut][ColBg] = strdup(xval.addr);
		if (XrmGetResource(xdb, "dmenu.outforeground", "*", &type, &xval))
			colors[SchemeOut][ColFg] = strdup(xval.addr);
		#if MORECOLOR_PATCH
		if (XrmGetResource(xdb, "dmenu.midbackground", "*", &type, &xval))
			colors[SchemeMid][ColBg] = strdup(xval.addr);
		if (XrmGetResource(xdb, "dmenu.midforeground", "*", &type, &xval))
			colors[SchemeMid][ColFg] = strdup(xval.addr);
		#endif // MORECOLOR_PATCH
		#if BORDER_PATCH
		if (XrmGetResource(xdb, "color6", "*", &type, &xval))
			colors[SchemeBorder][ColBg] = strdup(xval.addr);
		#endif // BORDER_PATCH
		#if HIGHLIGHT_PATCH
		if (XrmGetResource(xdb, "color0", "*", &type, &xval)) //selection highlight bg
			colors[SchemeSelHighlight][ColBg] = strdup(xval.addr);
		if (XrmGetResource(xdb, "color8", "*", &type, &xval)) //selection highlight fg
			colors[SchemeSelHighlight][ColFg] = strdup(xval.addr);
		if (XrmGetResource(xdb, "color8", "*", &type, &xval)) //hl bg
			colors[SchemeNormHighlight][ColBg] = strdup(xval.addr);
		if (XrmGetResource(xdb, "color0", "*", &type, &xval)) //hl fg
			colors[SchemeNormHighlight][ColFg] = strdup(xval.addr);
		#endif // HIGHLIGHT_PATCH
		#if HIGHPRIORITY_PATCH
		if (XrmGetResource(xdb, "dmenu.hpbackground", "*", &type, &xval))
			colors[SchemeHp][ColBg] = strdup(xval.addr);
		if (XrmGetResource(xdb, "dmenu.hpforeground", "*", &type, &xval))
			colors[SchemeHp][ColFg] = strdup(xval.addr);
		#endif // HIGHPRIORITY_PATCH
		#if EMOJI_HIGHLIGHT_PATCH
		if (XrmGetResource(xdb, "dmenu.hoverbackground", "*", &type, &xval))
			colors[SchemeHover][ColBg] = strdup(xval.addr);
		if (XrmGetResource(xdb, "dmenu.hoverforeground", "*", &type, &xval))
			colors[SchemeHover][ColFg] = strdup(xval.addr);
		if (XrmGetResource(xdb, "dmenu.greenbackground", "*", &type, &xval))
			colors[SchemeGreen][ColBg] = strdup(xval.addr);
		if (XrmGetResource(xdb, "dmenu.greenforeground", "*", &type, &xval))
			colors[SchemeGreen][ColFg] = strdup(xval.addr);
		if (XrmGetResource(xdb, "dmenu.yellowbackground", "*", &type, &xval))
			colors[SchemeYellow][ColBg] = strdup(xval.addr);
		if (XrmGetResource(xdb, "dmenu.yellowforeground", "*", &type, &xval))
			colors[SchemeYellow][ColFg] = strdup(xval.addr);
		if (XrmGetResource(xdb, "dmenu.bluebackground", "*", &type, &xval))
			colors[SchemeBlue][ColBg] = strdup(xval.addr);
		if (XrmGetResource(xdb, "dmenu.blueforeground", "*", &type, &xval))
			colors[SchemeBlue][ColFg] = strdup(xval.addr);
		if (XrmGetResource(xdb, "dmenu.purplebackground", "*", &type, &xval))
			colors[SchemePurple][ColBg] = strdup(xval.addr);
		if (XrmGetResource(xdb, "dmenu.purpleforeground", "*", &type, &xval))
			colors[SchemePurple][ColFg] = strdup(xval.addr);
		if (XrmGetResource(xdb, "dmenu.redbackground", "*", &type, &xval))
			colors[SchemeRed][ColBg] = strdup(xval.addr);
		if (XrmGetResource(xdb, "dmenu.redforeground", "*", &type, &xval))
			colors[SchemeRed][ColFg] = strdup(xval.addr);
		#endif // EMOJI_HIGHLIGHT_PATCH
		XrmDestroyDatabase(xdb);
	}
}
