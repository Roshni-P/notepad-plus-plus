#pragma once

#include <Windows.h>

namespace NppDarkMode
{
	struct Options
	{
		bool enable = false;
		bool enableExperimental = false;
		bool enableMenubar = false;
		bool enableScrollbarHack = false;
	};

	void initDarkMode();				// pulls options from NppParameters
	void refreshDarkMode(HWND hwnd, bool forceRefresh = false);	// attempts to apply new options from NppParameters, sends NPPM_INTERNAL_REFRESHDARKMODE to hwnd's top level parent

	bool isEnabled();
	bool isDarkMenuEnabled();
	bool isExperimentalEnabled();
	bool isScrollbarHackEnabled();

	bool isExperimentalActive();
	bool isExperimentalSupported();

	COLORREF invertLightness(COLORREF c);
	COLORREF invertLightnessSofter(COLORREF c);

	COLORREF getBackgroundColor();
	COLORREF getSofterBackgroundColor();
	COLORREF getHotBackgroundColor();
	COLORREF getPureBackgroundColor();
	COLORREF getTextColor();
	COLORREF getDarkerTextColor();
	COLORREF getEdgeColor();
	COLORREF getErrorBackgroundColor();

	HBRUSH getBackgroundBrush();
	HBRUSH getPureBackgroundBrush();
	HBRUSH getSofterBackgroundBrush();
	HBRUSH getHotBackgroundBrush();
	HBRUSH getErrorBackgroundBrush();

	// handle events
	bool handleSettingChange(HWND hwnd, LPARAM lParam); // true if dark mode toggled

	// processes messages related to UAH / custom menubar drawing.
	// return true if handled, false to continue with normal processing in your wndproc
	bool runUAHWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam, LRESULT* lr);

	// from DarkMode.h
	void initExperimentalDarkMode(bool fixDarkScrollbar);
	void allowDarkModeForApp(bool allow);
	bool allowDarkModeForWindow(HWND hWnd, bool allow);
	void refreshTitleBarThemeColor(HWND hWnd);

	// enhancements to DarkMode.h
	void enableDarkScrollBarForWindowAndChildren(HWND hwnd);

	void subclassButtonControl(HWND hwnd);
	void subclassToolbarControl(HWND hwnd);
}

