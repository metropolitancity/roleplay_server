/*
            ========================================================
             fixes.inc - Community patch for buggy SA:MP functions.
            ========================================================
*/

#if defined _INC_SAMP_Community_fixes
	#endinput
#endif
#define _INC_SAMP_Community_fixes

/**
 * <!--
 * <transition target(.*?)/>
 * -->
*/
#if (__Pawn & 0x0F) >= 0x0A
const _HIDE_THE_FIXES_COMMENT_1 = 1;
#endif
/**
 * <!--
 * :::::::: README ::::::::
 *
 * To read the generated XML output, copy `pawndoc.xsl` from
 * `github.com/pawn-lang/pawndoc` to `xml/` inside your compiler directory
 * (usually `pawno/xml/`).
 *
 * This information goes very close to the top of the generated XML
 * documentation (because of include dependency orders), but doesn't appear in
 * the visual output.
 * -->
*/
/**
 * <!--
 * There is <a href="https://github.com/Zeex/pawn/issues/184">a bug</a> in the
 * old compiler related to outputting documentation on state transitions ().  So
 * after generation of the XML file, you should clean it up with the following
 * RegEx replacement:
 *
 * Search: <transition target(.*?)/>
 * Replace: (nothing)
 *
 * This works 99% of the time, though you may get one where the corrupted target
 * includes the character `/`, in which case you should manually delete them.
 * Note that YSI now includes manual documentation for transitions, but these
 * all include the parameter `keep="true"`, which exists simply to not match
 * that RegEx.  I also put the search at the top of this block so it is easier
 * to find in the output code.  This is fixed in the community compiler, but
 * thanks to <a href="https://github.com/pawn-lang/compiler/issues/674">a
 * different bug</a> tricks are needed to hide these comments.
 * -->
 */
#if (__Pawn & 0x0F) >= 0x0A
const _HIDE_THE_FIXES_COMMENT_2 = 2;
#endif
// Do not remove the spaces before `summary`.  The compiler crashes!
/**
 * <library name="fixes.inc"   summary="Community patches for buggy SA:MP functions.">
 * <summary pawndoc="true">
 *   This library uses the enhanced <em>pawndoc.xsl</em> from
 *   <a href="https://github.com/pawn-lang/pawndoc">pawn-lang/pawndoc</a>.  This
 *   XSL has features such as library and markdown support, and will not render
 *   this message when used.
 * </summary>
 *
 * <section>
 *             Introduction
 * </section>
 *
 * <p>SA:MP is beta software written by a small team in their spare time, thus
 * it has bugs (as does all software).  Some of these have been known for a long
 * time but are low priority due to their minor effects, others go undiscovered
 * for a long time.  Many of these bugs have solutions which can be implemented
 * in PAWN (and this may be simpler than implementing them in the SA:MP source
 * code).  This include aims to collect fixes for as many of these bugs as
 * possible from the community (i.e. anyone who has a fix) together in to one
 * easy to use place for everyone's benefit.</p>
 *
 * <section>
 *             Use
 * </section>
 *
 * <p>To use this, simply include it after the default SA:MP functions, but
 * before third party includes:</p>
 *
 * <code>
 *     #include &lt;a_samp&gt;                                                  <br />
 *     // Any default re-definitions should go here.                            <br />
 *     //#undef MAX_PLAYERS                                                     <br />
 *     //#define MAX_PLAYERS 10                                                 <br />
 *     #include &lt;fixes&gt;                                                   <br />
 *     #include &lt;other&gt;
 * </code>
 *
 * <p>To disable any fix for whatever reason simply do:</p>
 *
 * <code>#define FIX_&lt;name&gt; 0</code>
 *
 * <p>For example, to disable all the file.inc fixes if you always correctly
 * check the file handle, do:</p>
 *
 * <code>
 *     #include &lt;a_samp&gt;                                                  <br />
 *     #define FIX_file_inc 0                                                   <br />
 *     #include &lt;fixes&gt;                                                   <br />
 *     #include &lt;other&gt;
 * </code>
 *
 * <p>All the names of the fixes are single words, and are all listed with their
 * fix descriptions below.</p>
 *
 * <p>If you only have one script running on your server (i.e. no
 * FilterScripts), you can use this define to improve the fixes.inc code:</p>
 *
 * <code>
 *     #include &lt;a_samp&gt;                                                  <br />
 *     #define FIXES_Single 1                                                   <br />
 *     #include &lt;fixes&gt;                                                   <br />
 *     #include &lt;other&gt;
 * </code>
 *
 * <section>
 *             Options
 * </section>
 *
 * <p>There are a few options for improved execution of this script.  Define
 * these symbols as <c>1</c> before you include fixes.inc (remove them or set
 * them to <c>0</c> to disable them):</p>
 *
 * <ul>
 *   <symbol name="FIXES_Single">You only have one script running (no
 *       filterscripts), simplify the code.</symbol>
 *   <symbol name="FIXES_SilentKick">When a player is kicked for illegal
 *       mods/vehicles, don't send them a message.</symbol>
 *   <symbol name="FIXES_Debug">Additional information in the server
 *       console.</symbol>
 * </ul>
 *
 * <p>A few fixes are disabled by default, to enable them all do:</p>
 *
 * <code>
 * #define GetPlayerDialog     1                                                <br />
 * #define file_inc            1                                                <br />
 * #define random              1                                                <br />
 * #define HideMenuForPlayer_2 1                                                <br />
 * #define GameTextStyles      1                                                <br />
 * #define GetPlayerWeather    1                                                <br />
 * #define GetWeather          1                                                <br />
 * #define GetWorldTime        1
 * </code>
 *
 * <p>Or more simply (and future-proof-ly):</p>
 *
 * <code>
 * #define FIXES_EnableAll                                                      <br />
 * #define FIXES_EnableDeprecated
 * </code>
 *
 * <section>
 *             Expansion
 * </section>
 *
 * <p>The file is fairly well documented, with a list of the currently
 * (hopefully) fixed bugs at the top.  If you know of others, or have solutions
 * for others, it would be greatly appreciated if you could post them as issues
 * on this repository.  The fixes also need extensive testing to find bugs in
 * the fixes themselves.</p>
 *
 * <p>Again, this is a community project, merely managed by Y_Less and others -
 * if anyone has comments, contributions, criticisms etc. please again post them
 * as issues on the repository.  This includes additions to source code,
 * documentation, presentation, translations (mainly of this documentation -
 * multiple versions of the include should be avoided to reduce fragmentation),
 * or any other related area you can think of.</p>
 *
 * <section>
 *             Other Fixes
 * </section>
 *
 * <p>There are a few other includes which aim to fix issues too large to be
 * included here:</p>
 *
 * <ul>
 *   <li><a href="https://sampforum.blast.hk/showthread.php?tid=435525">Timerfix</a> -
 *       <a href="https://github.com/udan11">udan11 (Dan..)</a>'s fixes to make
 *       "SetTimer" and "SetTimerEx" vastly more accurate in their delays.</li>
 *   <li><a href="https://sampforum.blast.hk/showthread.php?tid=303682">SQLitei</a> -
 *       <a href="https://github.com/oscar-broman/">Slice</a>'s fixes and
 *       improvements for many SQLite functions.</li>
 * </ul>
 *
 * <section>
 *             Bugs
 * </section>
 *
 * <p>Originally Posted by <a href="https://github.com/Y-Less/">Y_Less</a>:</p>
 *
 * <p><em>[This] is beta software written by a small team in their spare time,
 * thus it has bugs (as does all software).  This software is explicitly
 * designed to solve bugs, not cause them, but there may still be bugs.</em></p>
 *
 * <p>The most likely cause of bugs is certain combinations of disabled fixes.
 * Some fixes are inter-mixed and while they SHOULD work when the fixes they are
 * combined with are disabled, not every combination has been tested.  There are
 * literally billions of possible combinations - if you find one that doesn't
 * compile or work, please tell us.</p>
 *
 * <section>
 *             Style Rules
 * </section>
 *
 * <ul>
 * <li>All globals should be <c>static stock</c> whenever possible (so they can
 *     only be accessed from this one file).</li>
 * <li>Statics must start with <c>FIXES_gs</c>, and all other globals with
 *     <c>FIXES_g</c>.</li>
 * <li>All functions not overriding existing functions must start with
 *     <c>FIXES_</c>.</li>
 * <li>Macros must be upper case, use underscores, and start <c>FIXES_</c>:
 *     <c>FIXES_LIKE_THIS</c>.</li>
 * <li>Functions should be upper camel case (as the original functions are)
 *     <c>FIXES_LikeThis</c>.</li>
 * <li>Globals (after the prefix) should be upper camel case <c>LikeThis</c>,
 *     and locals lower camel case <c>likeThis</c>.</li>
 * <li>ALS should be used to hook functions and callbacks.  See
 *     <a href="https://sampforum.blast.hk/showthread.php?tid=570910">this topic</a> for
 *     more details.</li>
 * <li>The ALS prefix for chaining is <c>FIXES_</c>.</li>
 * <li>When redefining a native, add a <c>BAD_</c> external name declaration
 *     with the <c>_ALS_</c> definition so that others may use the original
 *     native if they so desire (with the caveat that it may break all fixes).
 *     Note the <c>BAD_</c> name is meant to indicate the possibility of
 *     breaking the fix, not a comment on the original native function.</li>
 * <li>The ALS hook defines used here are a little different to the normal ones
 *     as this file assumes that it is always first.  The pattern is:
 *
 * <code>
 *         ///                                                                  <br />
 *         /// &lt;remarks&gt;Information about fix here&lt;/remarks&gt;        <br />
 *         /// &lt;fixes&gt;NameOfFixHere&lt;/fixes&gt;                         <br />
 *         ///                                                                  <br />
 *                                                                              <br />
 *         #if _FIXES_SAMP &amp;&amp; defined _ALS_NameOfFixHere                <br /><indent />
 *             #error _ALS_NameOfFixHere defined                                <br />
 *         #endif                                                               <br />
 *         native BAD_NameOfFixHere(params) = NameOfFixHere;                    <br />
 *                                                                              <br />
 *         ///                                                                  <br />
 *         /// &lt;remarks&gt;Information about fix here&lt;/remarks&gt;        <br />
 *         /// &lt;fixes&gt;NameOfFixHere&lt;/fixes&gt;                         <br />
 *         ///                                                                  <br />
 *                                                                              <br />
 *         #if FIX_NameOfFixHere                                                <br /><indent />
 *             stock FIXES_NameOfFixHere(params)                                <br /><indent />
 *             {                                                                <br /><indent /><indent />
 *                 return 0;                                                    <br /><indent />
 *             }                                                                <br />
 *                                                                              <br /><indent />
 *             // The trailing `(` is VERY important to keep future `native X() = Y;`s working. <br /><indent />
 *             #if _FIXES_SAMP                                                  <br /><indent /><indent />
 *                 #define _ALS_NameOfFixHere                                   <br /><indent /><indent />
 *                 #define NameOfFixHere( FIXES_NameOfFixHere(                  <br /><indent />
 *             #endif                                                           <br /><indent />
 *             // `__` suffix version for hidden calls to the originals.        <br /><indent />
 *             #define _ALS_NameOfFixHere__                                     <br /><indent />
 *             #define NameOfFixHere__( FIXES_NameOfFixHere(                    <br />
 *         #endif
 *     </code>
 *
 *     A copyable version of this pattern is at the end of the file.</li>
 * <li>Enums start with <c>E_</c> or <c>e_</c> depending on type, then follow
 *     rules for macros.</li>
 * <li>NO libraries should be included - not even the default SA:MP ones.  Let
 *     the user do it.  This is simplified by having copies of all natives.</li>
 * <li>Due to the above rule, you cannot assume any third party libraries AT
 *     ALL, so do not use them.  This can lead to some code duplication, but
 *     also means that the version of the code used here can be tailored for
 *     optimisations.</li>
 * <li>Certain terms may be shortened when dealing with long callback names to
 *     avoid compile truncation warnings (max symbol length is 31).  Current
 *     list:
 * <ul>
 *         <li><c>Checkpoint</c>: <c>CP</c></li>
 *         <li><c>Update   </c>: <c>Upd</c></li>
 *         <li><c>TextDraw </c>: <c>TD</c></li>
 *         <li><c>Object   </c>: <c>Obj</c></li>
 *         <li><c>Player   </c>: <c>P</c></li>
 * </ul></li>
 * <li>Document all fixes at the top of the file, and highlight code.</li>
 * <li>4 space TABS - do not edit this file in PAWNO unless you know how to
 *     correct the indentation.</li>
 * <li>All rules have exceptions, but they must be justifiable.  For example
 *     <c>IS_FILTERSCRIPT</c> is a global variable, but is not called
 *     <c>FIXES_gIsFilterscript</c> to better match the <c>FILTERSCRIPT</c>
 *     macro it replaces.  Now a macro for <c>_FIXES_gIsFilterscript</c>.</li>
 * <li>Variables which need to be fully global (i.e. not <c>static</c>), but
 *     should not actually be used by other people (e.g. appear inside a macro)
 *     should be prefixed with <c>_FIXES</c> instead of <c>FIXES</c> to indicate
 *     their private use.</li>
 * <li>No comments beyond the end of column 80 (where the line in <em>PAWNO</em>
 *     is).</li>
 * <li>If a bug is fixed in some version of the server it can be conditionally
 *     included here.  This is done by checking for the existance of a native
 *     function introduced in the same server version.  For example
 *     <c>TogglePlayerControllable</c> was fixed in 0.3eRC6, the same time as
 *     the <c>SetObjectMaterial</c> native was introduced, thus the inclusion
 *     becomes:
 *
 * <code>
 *         #if !defined FIX_NameOfFixHere                                       <br /><indent />
 *             #if defined NativeInFixRelease                                   <br /><indent /><indent />
 *                 #if FIXES_EnableDeprecated                                   <br /><indent /><indent /><indent />
 *                     static _FIXES_OPTION FIX_NameOfFixHere = FIXES_EnableDeprecated; <br /><indent /><indent />
 *                 #else                                                        <br /><indent /><indent /><indent />
 *                     _FIXES_CONST_PAWNDOC(FIX_NameOfFixHere = FIXES_EnableDeprecated); <br /><indent /><indent />
 *                 #endif                                                       <br /><indent /><indent />
 *                 #define FIX_NameOfFixHere                FIXES_EnableDeprecated <br /><indent />
 *             #else                                                            <br /><indent /><indent />
 *                 static _FIXES_OPTION FIX_NameOfFixHere = _FIXES_DEFAULT;      <br /><indent /><indent />
 *                 #define FIX_NameOfFixHere                _FIXES_DEFAULT      <br /><indent />
 *             #endif                                                           <br />
 *         #elseif _FIXES_IS_UNSET(FIX_NameOfFixHere)                           <br /><indent />
 *             #undef FIX_NameOfFixHere                                         <br /><indent />
 *             static stock FIX_NameOfFixHere = 2;                              <br /><indent />
 *             #define FIX_NameOfFixHere                    (2)                 <br />
 *         #elseif FIX_NameOfFixHere                                            <br /><indent />
 *             #undef FIX_NameOfFixHere                                         <br /><indent />
 *             static stock FIX_NameOfFixHere = 1;                              <br /><indent />
 *             #define FIX_NameOfFixHere                    (1)                 <br />
 *         #else                                                                <br /><indent />
 *             #undef FIX_NameOfFixHere                                         <br /><indent />
 *             static stock FIX_NameOfFixHere = 0;                              <br /><indent />
 *             #define FIX_NameOfFixHere                    (0)                 <br />
 *         #endif
 * </code>
 *
 *     This only includes this fix if that native doesn't exist.  A copyable
 *     version of this pattern is at the end of the file.</li>
 * <li>To reduce general memory consumption, strings in this include are stored
 *     globally in constant arrays and referenced.  This is EXACTLY as fast as
 *     using the string constants directly, but means that strings are not
 *     stored in the assembly multiple times (unless the string is only used
 *     once, in which case it's more work for no gain).  See
 *     <a href="http://forum.sa-mp.com/showpost.php?p=1795601">this post</a>
 *     for more details.</li>
 * <li>DO NOT EDIT THIS FILE IN PAWNO OR ON GITHUB.  Both mess up the spacing -
 *     GitHub in an almost irreversible way (except for the fact that nothing is
 *     irreversible in source control.  Pawno spacing is less tricky to solve,
 *     and can be worked around if you know when it uses spaces and tabs - in
 *     short, always write code first THEN indent and you won't have a problem
 *     (in that editor at least, that is normally a bad way to write code).</li>
 * </ul>
 * <section>
 *             Documentation Explanation
 * </section>
 *
 * <p>The <em>fixes.inc</em> code itself now contains all of the documentation
 * in its header, formatted using the compiler's natively supported pawn-doc,
 * plus some custom XSL.  Previously <em>README.md</em> and the header had to be
 * kept in sync manually.  Now you can just compile a script with <c>-r</c> and
 * get a large amount of XML documentation, including all of this header in a
 * <c>&lt;library&gt;&lt;/library&gt;</c> pair.  The repository comes with a
 * file called <em>markdown.xsl</em> that, when saved as
 * <em>pawno/xml/pawndoc.xsl</em>, will transform that XML to markdown to keep
 * <em>README.md</em> fully up-to-data almost automatically.</p>
 *
 * <p>The descriptions of the fixes all look like:</p>
 *
 * <code lang="xml">
 *     &lt;fix name="Short Name" disabled="true" fixed="Optional server version of official fix where applicable"&gt; <br /><indent />
 *         &lt;problem&gt;                                                                                                        <br /><indent />
 *             Description of problem.                                                                                            <br /><indent /><indent />
 *         &lt;/problem&gt;                                                                                                       <br /><indent />
 *         &lt;solution&gt;                                                                                                       <br /><indent /><indent />
 *             Description of solution.                                                                                           <br /><indent />
 *         &lt;/solution&gt;                                                                                                      <br /><indent />
 *         &lt;see&gt;Relevant functions.&lt;/see&gt;                                                                             <br /><indent />
 *         &lt;author    href="Optional address of their profile"&gt;Person who wrote the fix&lt;/author&gt;                      <br /><indent />
 *         &lt;post      href="Optional link to the original post where applicable." /&gt;                                        <br />
 *     &lt;/fix&gt;
 * </code>
 *
 *
 *
 * </library>
 *//** */

/*

    88        88                                   88
    88        88                                   88
    88        88                                   88
    88aaaaaaaa88   ,adPPYba,  ,adPPYYba,   ,adPPYb,88   ,adPPYba,  8b,dPPYba,
    88""""""""88  a8P_____88  ""     `Y8  a8"    `Y88  a8P_____88  88P'   "Y8
    88        88  8PP"""""""  ,adPPPPP88  8b       88  8PP"""""""  88
    88        88  "8b,   ,aa  88,    ,88  "8a,   ,d88  "8b,   ,aa  88
    88        88   `"Ybbd8"'  `"8bbdP"Y8   `"8bbdP"Y8   `"Ybbd8"'  88



*/

#if !defined _inc_fixes
	#define _inc_fixes
#endif

#pragma tabsize 4
#pragma semicolon 1
#pragma ctrlchar '\\'
#pragma rational Float

#define _FIXES_ENUM enum

#if (__Pawn & 0x0F) >= 0x0A
	#define _FIXES_NEW_COMPILER (1)
#else
	#define _FIXES_NEW_COMPILER (0)
#endif

#if _FIXES_NEW_COMPILER
	#if defined __PawnBuild
		// Extra flags.
		#if __PawnBuild >= 4
			#pragma option -(+
		#endif

		// Use `static enum` if it is available.
		#if __PawnBuild >= 2
			#undef _FIXES_ENUM
			#define _FIXES_ENUM static enum
		#endif
	#endif

	// Stupid "warning" that should not exist ever:
	#pragma warning push        // Save the warning state.
	#pragma warning disable 207 // Disable unknown pragmas warning.
	#pragma disablerecursion    // Disable recursion warning if it exists.
	#pragma warning pop         // Maybe re-enable unknown pragmas warning.
#endif

// Detect compiling on open.mp.
#if !defined OPEN_MP
	// Try them all until one sticks.  If we already included one these
	// repeat includes are internally short-circuited, so no harm done.
	//#if !defined _samp_included
	//	#tryinclude <a_samp>
	//	#tryinclude "a_samp"
	//#endif
	//#if !defined _samp_included
	//	#tryinclude <a_npc>
	//	#tryinclude "a_npc"
	//#endif
	#if !defined _samp_included
		#error Include <a_samp> or <a_npc> before fixes.inc
	#endif
	#if defined GetDistanceFromMeToPoint
		#define _FIXES_NPC 1
	#elseif defined GetDistanceFromMeToPoint__
		#define _FIXES_NPC 1
	#else
		#define _FIXES_NPC 0
		// Do nothing.
	#endif
	#define _FIXES_SAMP 1
	#define _FIXES_OMP 0
#elseif defined OPENMP_SAMP
	// Backwards-compatible development mode.
	#if defined OPENMP_COMPAT
		#define _FIXES_SAMP 1
	#else
		#define _FIXES_SAMP 0
	#endif
	#define _FIXES_OMP 1
	#define _FIXES_NPC 0
#else
	#error fixes.inc is not required for open.mp
#endif

/**
 * <library>fixes.inc</library>
 * <remarks>
 * True on the first pass of the compiler, and not on any others.  This is the
 * pass of the compiler in which functions are collected, so that later passes
 * can call functions defined later in code.  We can detect this pass using
 * <c>#if defined FutureFunction</c> (here we use <c>_FIXES_DetermineOS</c>
 * because it is always compiled).  If it exists, this can't be the first pass;
 * if it doesn't, it is.  We can then use this pass knowledge to generate
 * pawndoc comments for macros in only the first pass.
 * </remarks>
 */

#if defined _FIXES_DetermineOS
	#define _FIXES_FIRST_PASS                    (0)
#else
	static stock _FIXES_FIRST_PASS = 1;
	#define _FIXES_FIRST_PASS                    (1)
#endif

/**
 * <library>fixes.inc</library>
 * <remarks>
 * Creates fake functions that Pawndoc comments can be attached to in the first
 * compilation phase, before the real macros are created.  Macros can't have
 * documentation comments, but why not?  They need documenting...
 * <p/>
 * Used internally as <c>_FIXES_FUNC_PAWNDOC</c>.
 * <p/>
 * This creates a native of the same name, then calls it from a special function
 * (called <c>PAWNDOC</c>) with a state set to the name of this function, to
 * avoid declaring multiple functions in the XML while ensuring that this fake
 * function is in the XML.  Natives aren't in the output unless they are called,
 * but we don't have to call them correctly because the container function is
 * never called.  You do need a fallback version of `PAWNDOC` to catch all other
 * state variations declared elsewhere in your script.
 * <p/>
 * <code>
 *     #if defined MACRO_NAME                                                   <br /><indent />
 *         // `#define MACRO_NAME` exists previously, don't document it here.   <br /><indent />
 *         _FIXES_HIDE_PAWNDOC(SIMILAR_NAME);                                   <br />
 *     #else                                                                    <br /><indent />
 *         // Doesn't exist.  Document it and define it.                        <br /><indent />
 *         _FIXES_FUNC_PAWNDOC(MACRO_NAME(parameters));                         <br /><indent />
 *         #define MACRO_NAME(%0) (%0)                                          <br />
 *     #endif
 * </code>
 * <br />
 * </remarks>
 */

#if _FIXES_FIRST_PASS
	// First compiler pass only.
	#define _FIXES_FUNC_PAWNDOC(%0(%1)); native %0(%1) = __PAWNDOC; stock PAWNDOC _FIXES_DEFER_EXPANSION() <__PAWNDOC:%0> { (%0()); }
#else
	#define _FIXES_FUNC_PAWNDOC(%0(%1));
#endif

// Strip tags from states.
#define __PAWNDOC:%0:%1> __PAWNDOC:%1>

// Defer macro expansion.
#define _FIXES_DEFER_EXPANSION

_FIXES_FUNC_PAWNDOC(FUNC_PAWNDOC(const symbol[]));

/**
 * <library>fixes.inc</library>
 * <remarks>
 * Creates fake constants that Pawndoc comments can be attached to in the first
 * compilation phase, before the real macros are created.  Macros can't have
 * documentation comments, but why not?  They need documenting...
 * <p/>
 * Used internally as <c>_FIXES_CONST_PAWNDOC</c>.
 * <p/>
 * This creates a static stock of the same name to attach the documentation to,
 * before actually defining the macro.
 * <p/>
 * <code>
 *     #if defined MACRO_NAME                                                   <br /><indent />
 *         // `#define MACRO_NAME` exists previously, don't document it here.   <br /><indent />
 *         _FIXES_HIDE_PAWNDOC(SIMILAR_NAME);                                   <br />
 *     #else                                                                    <br /><indent />
 *         // Doesn't exist.  Document it and define it.                        <br /><indent />
 *         _FIXES_CONST_PAWNDOC(MACRO_NAME = 42);                               <br /><indent />
 *         #define MACRO_NAME (42)                                              <br />
 *     #endif
 * </code>
 * <br />
 * </remarks>
 */

#if _FIXES_FIRST_PASS
	// First compiler pass only.
	#define _FIXES_CONST_PAWNDOC(%0=%1); static stock %0 = %1;
#else
	#define _FIXES_CONST_PAWNDOC(%0);
#endif

_FIXES_FUNC_PAWNDOC(CONST_PAWNDOC(const symbol[] = 0));

/**
 * <library>fixes.inc</library>
 * <remarks>
 * Create a <c>const</c> that is never used, which has pawndoc documentation
 * attached to it.  This seems to be the best way to prevent the documentation
 * from appearing in XML (<c>-r</c>) output - even conditional compilation
 * doesn't work on comments.  Used internally as <c>_FIXES_HIDE_PAWNDOC</c>.
 * <p />
 * The input should have some unique name, so when using it within an ifdef
 * block, don't use the same name as the tested symbol, because the the
 * replacement in question will be applied to the hidden variable as well.
 * <p />
 * This should also be a globally unique symbol name, because this only works
 * with `<c>const</c>`, not `<c>static const</c>`.
 * </remarks>
 */

_FIXES_FUNC_PAWNDOC(HIDE_PAWNDOC(const symbol[]));
#define _FIXES_HIDE_PAWNDOC(%0); const %0 = 0;

/**
 * <library>fixes.inc</library>
 * <remarks>
 * There's a bug with the pawndoc for enums.  They loose the documentation, or
 * get some other documentation unless they're immediately followed by another
 * declaration, most notably a function.  This uses the same
 * <c>PAWNDOC&lt;&gt;</c> trick as <c>FUNC_PAWNDOC</c> to use the <c>enum</c>
 * name as a symbol, this time passing it to a function that should always
 * exist.  This ensures the docs are attached to the correct symbol and the
 * additional function is well documented.
 * </remarks>
 */

_FIXES_FUNC_PAWNDOC(ENUM_PAWNDOC(const symbol[]));
#define _FIXES_ENUM_PAWNDOC(%0); stock PAWNDOC _FIXES_DEFER_EXPANSION() <__PAWNDOC:%0> { random(_:%0); }

/**
 * <library>fixes.inc</library>
 * <remarks>
 * <p>Test if something is defined, but without a value.  For example:</p>
 *
 * <code>
 *     #define FIX_AddMenuItem
 * </code>
 *
 * <p>Instead of:</p>
 *
 * <code>
 *     #define FIX_AddMenuItem 1
 * </code>
 *
 * <p>Exploits the fact that <c>FIX_AddMenuItem - 1</c> is valid in both cases.
 * When a value is set this becomes (say) <c>0 - 1</c>, i.e. a sum.  When it
 * isn't set this becomes <c>-1</c>, i.e. just the unary value <c>-1</c>.  Also
 * exploits operator precedence - <c>2 * 0 - 1</c> is not the same as
 * <c>2 * (0 - 1)</c>.  The former is <c>-1</c>, the latter is <c>-2</c>.  The
 * expression is never true for any real number (it might be for complex
 * expressions that change the evaluation order).  This can be shown be trying
 * to solve <c>2n - 1 = 2(n - 1)</c> - you end up trying to prove that
 * <c>n = n - 0.5</c>, a contradiction.  Q.E.D.</p>
 *
 * <p>Conversely, when no value is given this becomes <c>2 * -1 = 2 * (-1)</c>,
 * which is trivially correct.</p>
 * </remarks>
 */

_FIXES_FUNC_PAWNDOC(_FIXES_IS_UNSET(const symbol[]));
#define _FIXES_IS_UNSET(%0) ((2*%0-1)==2*(%0-1))

/*

     ad88888ba                                 88
    d8"     "8b                ,d       ,d     ""
    Y8,                        88       88
    `Y8aaaaa,     ,adPPYba,  MM88MMM  MM88MMM  88  8b,dPPYba,    ,adPPYb,d8  ,adPPYba,
      `"""""8b,  a8P_____88    88       88     88  88P'   `"8a  a8"    `Y88  I8[    ""
            `8b  8PP"""""""    88       88     88  88       88  8b       88   `"Y8ba,
    Y8a     a8P  "8b,   ,aa    88,      88,    88  88       88  "8a,   ,d88  aa    ]8I
     "Y88888P"    `"Ybbd8"'    "Y888    "Y888  88  88       88   `"YbbdP"Y8  `"YbbdP"'
                                                                 aa,    ,88
                                                                  "Y8bbdP"


*/

/**
 * <library>fixes.inc</library>
 * <remarks>
 * Require settings to be explicitly enabled or disabled, and show a warning for
 * every setting not mentioned.
 * </remarks>
 */

#if !defined FIXES_ExplicitSettings
	// The only setting that could ignore this setting.  For now the default is
	// `0`.  If the default changes this must become `static`.
	#define _FIXES_SETTING                       stock
	// The include needs `FIXES_ExplicitSettings` to be defined...
	#define FIXES_ExplicitSettings               (0)
	#define _FIXES_WARNING 1
	// If the warning include gets included it redefines `static _FIXES_SETTING`.
	#tryinclude "_fixes_settings"
	#undef _FIXES_WARNING
	// ...but the variable definition needs it to be undefined.
	#undef FIXES_ExplicitSettings
	static _FIXES_SETTING FIXES_ExplicitSettings = 0;
	#define FIXES_ExplicitSettings               (0)
#elseif _FIXES_IS_UNSET(FIXES_ExplicitSettings)
	#undef FIXES_ExplicitSettings
	static stock FIXES_ExplicitSettings = 2;
	#define FIXES_ExplicitSettings               (2)
	#define _FIXES_SETTING
#elseif FIXES_ExplicitSettings
	#undef FIXES_ExplicitSettings
	static stock FIXES_ExplicitSettings = 1;
	#define FIXES_ExplicitSettings               (1)
	#define _FIXES_SETTING
#else
	#undef FIXES_ExplicitSettings
	static stock FIXES_ExplicitSettings = 0;
	#define FIXES_ExplicitSettings               (0)
	#define _FIXES_SETTING                       stock
#endif

/**
 * <library>fixes.inc</library>
 * <remarks>
 * Enable everything, even things that probably shouldn't be enabled.
 * </remarks>
 */

#if !defined FIXES_EnableAll
	#define _FIXES_WARNING 2
	#tryinclude "_fixes_settings"
	#undef _FIXES_WARNING
	static _FIXES_SETTING FIXES_EnableAll = 0;
	#define FIXES_EnableAll                      (0)
#elseif _FIXES_IS_UNSET(FIXES_EnableAll)
	#undef FIXES_EnableAll
	static stock FIXES_EnableAll = 2;
	#define FIXES_EnableAll                      (2)
#elseif FIXES_EnableAll
	#undef FIXES_EnableAll
	static stock FIXES_EnableAll = 1;
	#define FIXES_EnableAll                      (1)
#else
	#undef FIXES_EnableAll
	static stock FIXES_EnableAll = 0;
	#define FIXES_EnableAll                      (0)
#endif

/**
 * <library>fixes.inc</library>
 * <remarks>
 * Enable all deprecated fixes (those that are no longer needed because they
 * were fixed in later server revisions).  Might causes errors and conflicts
 * with newer SA:MP includes.
 * </remarks>
 */

#if !defined FIXES_EnableDeprecated
	#define _FIXES_WARNING 3
	#tryinclude "_fixes_settings"
	#undef _FIXES_WARNING
	static _FIXES_SETTING FIXES_EnableDeprecated = 0;
	#define FIXES_EnableDeprecated               (0)
#elseif _FIXES_IS_UNSET(FIXES_EnableDeprecated)
	#undef FIXES_EnableDeprecated
	static stock FIXES_EnableDeprecated = 2;
	#define FIXES_EnableDeprecated               (2)
#elseif FIXES_EnableDeprecated
	#undef FIXES_EnableDeprecated
	static stock FIXES_EnableDeprecated = 1;
	#define FIXES_EnableDeprecated               (1)
#else
	#undef FIXES_EnableDeprecated
	static stock FIXES_EnableDeprecated = 0;
	#define FIXES_EnableDeprecated               (0)
#endif

/**
 * <library>fixes.inc</library>
 * <remarks>
 * Disable all fixes by default, and require them to be individually enabled
 * with <c>#define FIX_&lt;name&gt; 1</c>.
 * </remarks>
 */

#if !defined FIXES_DefaultDisabled
	#define _FIXES_WARNING 4
	#tryinclude "_fixes_settings"
	#undef _FIXES_WARNING
	static _FIXES_SETTING FIXES_DefaultDisabled = 0;
	#define FIXES_DefaultDisabled                (0)
	#define _FIXES_DEFAULT                       (1)
#elseif _FIXES_IS_UNSET(FIXES_DefaultDisabled)
	#undef FIXES_DefaultDisabled
	static stock FIXES_DefaultDisabled = 2;
	#define FIXES_DefaultDisabled                (2)
	// If we want things disabled by default and everything enabled, do it.
	#define _FIXES_DEFAULT                       FIXES_EnableAll
#elseif FIXES_DefaultDisabled
	#undef FIXES_DefaultDisabled
	static stock FIXES_DefaultDisabled = 1;
	#define FIXES_DefaultDisabled                (1)
	#define _FIXES_DEFAULT                       (0)
#else
	#undef FIXES_DefaultDisabled
	static stock FIXES_DefaultDisabled = 0;
	#define FIXES_DefaultDisabled                (0)
	#define _FIXES_DEFAULT                       (1)
#endif

/**
 * <library>fixes.inc</library>
 * <remarks>
 * Require fixes to be explicitly enabled or disabled, and show a warning for
 * every fix not mentioned.  Useful in combination with
 * <c>FIXES_DefaultDisabled</c>, so default <c>1</c> with that, <c>0</c>
 * otherwise.
 * </remarks>
 */

#if !defined FIXES_ExplicitOptions
	#define _FIXES_WARNING 5
	#tryinclude "_fixes_settings"
	#undef _FIXES_WARNING
	#if FIXES_DefaultDisabled
		static _FIXES_SETTING FIXES_ExplicitOptions = 1;
		#define FIXES_ExplicitOptions            (1)
		#define _FIXES_OPTION
	#else
		static _FIXES_SETTING FIXES_ExplicitOptions = 0;
		#define FIXES_ExplicitOptions            (0)
		#define _FIXES_OPTION                    stock
	#endif
#elseif _FIXES_IS_UNSET(FIXES_ExplicitOptions)
	#undef FIXES_ExplicitOptions
	static stock FIXES_ExplicitOptions = 2;
	#define FIXES_ExplicitOptions                (2)
	#define _FIXES_OPTION
#elseif FIXES_ExplicitOptions
	#undef FIXES_ExplicitOptions
	static stock FIXES_ExplicitOptions = 1;
	#define FIXES_ExplicitOptions                (1)
	#define _FIXES_OPTION
#else
	#undef FIXES_ExplicitOptions
	static stock FIXES_ExplicitOptions = 0;
	#define FIXES_ExplicitOptions                (0)
	#define _FIXES_OPTION                        stock
#endif

/**
 * <library>fixes.inc</library>
 * <remarks>
 * If this define is set to 1, then players will not be given a message when
 * they are kicked for cheats (mainly invalid vehicles and mods), instead they
 * will just loose connection to the server.
 * </remarks>
 */

#if !defined FIXES_SilentKick
	#define _FIXES_WARNING 6
	#tryinclude "_fixes_settings"
	#undef _FIXES_WARNING
	static _FIXES_SETTING FIXES_SilentKick = 0;
	#define FIXES_SilentKick                     (0)
#elseif _FIXES_IS_UNSET(FIXES_SilentKick)
	#undef FIXES_SilentKick
	static stock FIXES_SilentKick = 2;
	#define FIXES_SilentKick                     (2)
#elseif FIXES_SilentKick
	#undef FIXES_SilentKick
	static stock FIXES_SilentKick = 1;
	#define FIXES_SilentKick                     (1)
#else
	#undef FIXES_SilentKick
	static stock FIXES_SilentKick = 0;
	#define FIXES_SilentKick                     (0)
#endif

/**
 * <library>fixes.inc</library>
 * <remarks>
 * If this define is set to 1, then debug printing is turned on for any
 * functions which may use it.  Otherwise, the compiler entirely removes the
 * code to print anything, leaving no run-time overhead.
 * </remarks>
 */

#if !defined FIXES_Debug
	#define _FIXES_WARNING 7
	#tryinclude "_fixes_settings"
	#undef _FIXES_WARNING
	static _FIXES_SETTING FIXES_Debug = 0;
	#define FIXES_Debug                          (0)
	#define FIXES_PRINTF(%0);
#elseif _FIXES_IS_UNSET(FIXES_Debug)
	#undef FIXES_Debug
	static stock FIXES_Debug = 2;
	#define FIXES_Debug                          (2)
	#define FIXES_PRINTF                         _FIXES_PRINTF
#elseif FIXES_Debug
	#undef FIXES_Debug
	static stock FIXES_Debug = 1;
	#define FIXES_Debug                          (1)
	#define FIXES_PRINTF                         _FIXES_PRINTF
#else
	#undef FIXES_Debug
	static stock FIXES_Debug = 0;
	#define FIXES_Debug                          (0)
	#define FIXES_PRINTF(%0);
#endif

/**
 * <library>fixes.inc</library>
 * <remarks>
 * If this define is set to 1, then the old style include is used, with no
 * support for multiple scripts running at the same time on the server.  You
 * only have one script that uses <emph>fixes.inc</emph> running (no other
 * gamemodes or filterscripts).  Using this define will vastly simplify the code
 * in that case, as no cross-script communication is required, but will cause
 * bugs if there actually is another script running.
 * </remarks>
 */

#if !defined FIXES_Single
	#define _FIXES_WARNING 8
	#tryinclude "_fixes_settings"
	#undef _FIXES_WARNING
	static _FIXES_SETTING FIXES_Single = 1;
	#define FIXES_Single                         (1)
#elseif _FIXES_IS_UNSET(FIXES_Single)
	#undef FIXES_Single
	static stock FIXES_Single = 2;
	#define FIXES_Single                         (2)
#elseif FIXES_Single
	#undef FIXES_Single
	static stock FIXES_Single = 1;
	#define FIXES_Single                         (1)
#else
	#undef FIXES_Single
	static stock FIXES_Single = 0;
	#define FIXES_Single                         (0)
#endif

/**
 * <library>fixes.inc</library>
 * <remarks>
 * Hide a message at mode start if <c>FIXES_Single</c> is set, but this is NOT
 * the only script running <emph>fixes.inc</emph>.  This will entirely disable
 * the check, so should only be used if you are absolutely certain that no other
 * scripts are running at the same time (gamemodes or filterscripts).
 * </remarks>
 */

#if !defined FIXES_NoSingleMsg
	#define _FIXES_WARNING 9
	#tryinclude "_fixes_settings"
	#undef _FIXES_WARNING
	static _FIXES_SETTING FIXES_NoSingleMsg = 0;
	#define FIXES_NoSingleMsg                    (0)
#elseif _FIXES_IS_UNSET(FIXES_NoSingleMsg)
	#undef FIXES_NoSingleMsg
	static stock FIXES_NoSingleMsg = 2;
	#define FIXES_NoSingleMsg                    (2)
#elseif FIXES_NoSingleMsg
	#undef FIXES_NoSingleMsg
	static stock FIXES_NoSingleMsg = 1;
	#define FIXES_NoSingleMsg                    (1)
#else
	#undef FIXES_NoSingleMsg
	static stock FIXES_NoSingleMsg = 0;
	#define FIXES_NoSingleMsg                    (0)
#endif

/**
 * <library>fixes.inc</library>
 * <remarks>
 * If this define is set to 1, then the server will not give a message when
 * <see>GetServerVarAsString</see> and related functions are used without a
 * valid directory redirect.
 * </remarks>
 */

#if !defined FIXES_NoServerVarMsg
	#define _FIXES_WARNING 10
	#tryinclude "_fixes_settings"
	#undef _FIXES_WARNING
	static _FIXES_SETTING FIXES_NoServerVarMsg = 0;
	#define FIXES_NoServerVarMsg                 (0)
#elseif _FIXES_IS_UNSET(FIXES_NoServerVarMsg)
	#undef FIXES_NoServerVarMsg
	static stock FIXES_NoServerVarMsg = 2;
	#define FIXES_NoServerVarMsg                 (2)
#elseif FIXES_NoServerVarMsg
	#undef FIXES_NoServerVarMsg
	static stock FIXES_NoServerVarMsg = 1;
	#define FIXES_NoServerVarMsg                 (1)
#else
	#undef FIXES_NoServerVarMsg
	static stock FIXES_NoServerVarMsg = 0;
	#define FIXES_NoServerVarMsg                 (0)
#endif

/**
 * <library>fixes.inc</library>
 * <remarks>
 * If this define is set to 1, then the server will not give a message when
 * <see>GetMaxPlayers</see> doesn't match <c>MAX_PLAYERS</c>.
 * </remarks>
 */

#if !defined FIXES_NoGetMaxPlayersMsg
	#define _FIXES_WARNING 11
	#tryinclude "_fixes_settings"
	#undef _FIXES_WARNING
	static _FIXES_SETTING FIXES_NoGetMaxPlayersMsg = 0;
	#define FIXES_NoGetMaxPlayersMsg             (0)
#elseif _FIXES_IS_UNSET(FIXES_NoGetMaxPlayersMsg)
	#undef FIXES_NoGetMaxPlayersMsg
	static stock FIXES_NoGetMaxPlayersMsg = 2;
	#define FIXES_NoGetMaxPlayersMsg             (2)
#elseif FIXES_NoGetMaxPlayersMsg
	#undef FIXES_NoGetMaxPlayersMsg
	static stock FIXES_NoGetMaxPlayersMsg = 1;
	#define FIXES_NoGetMaxPlayersMsg             (1)
#else
	#undef FIXES_NoGetMaxPlayersMsg
	static stock FIXES_NoGetMaxPlayersMsg = 0;
	#define FIXES_NoGetMaxPlayersMsg             (0)
#endif

/**
 * <library>fixes.inc</library>
 * <remarks>
 * If this define is set to 1, then compiling with <c>-r</c> will attempt to
 * hide as many of the functions and variables in fixes.inc from the output XML
 * as possible.  This will vastly simplify the generated documentation (at least
 * the visible parts, this is done by embeddeding XML comments in the output, so
 * all the data still exists, just hidden in the file).
 * </remarks>
 */

#if !defined FIXES_NoPawndoc
	#define _FIXES_WARNING 12
	#tryinclude "_fixes_settings"
	#undef _FIXES_WARNING
	static _FIXES_SETTING FIXES_NoPawndoc = 0;
	#define FIXES_NoPawndoc                      (0)
#elseif _FIXES_IS_UNSET(FIXES_NoPawndoc)
	#undef FIXES_NoPawndoc
	static stock FIXES_NoPawndoc = 2;
	#define FIXES_NoPawndoc                      (2)
#elseif FIXES_NoPawndoc
	#undef FIXES_NoPawndoc
	static stock FIXES_NoPawndoc = 1;
	#define FIXES_NoPawndoc                      (1)
#else
	#undef FIXES_NoPawndoc
	static stock FIXES_NoPawndoc = 0;
	#define FIXES_NoPawndoc                      (0)
#endif

/**
 * <library>fixes.inc</library>
 * <remarks>
 * You know that an invalid timer is ID <c>0</c>, not <c>-1</c>, so exclude the
 * excess code designed to warn about/detect people using <c>-1</c>.
 * </remarks>
 */

#if !defined FIXES_CorrectInvalidTimerID
	#define _FIXES_WARNING 13
	#tryinclude "_fixes_settings"
	#undef _FIXES_WARNING
	static _FIXES_SETTING FIXES_CorrectInvalidTimerID = 0;
	#define FIXES_CorrectInvalidTimerID          (0)
#elseif _FIXES_IS_UNSET(FIXES_CorrectInvalidTimerID)
	#undef FIXES_CorrectInvalidTimerID
	static stock FIXES_CorrectInvalidTimerID = 2;
	#define FIXES_CorrectInvalidTimerID          (2)
#elseif FIXES_CorrectInvalidTimerID
	#undef FIXES_CorrectInvalidTimerID
	static stock FIXES_CorrectInvalidTimerID = 1;
	#define FIXES_CorrectInvalidTimerID          (1)
#else
	#undef FIXES_CorrectInvalidTimerID
	static stock FIXES_CorrectInvalidTimerID = 0;
	#define FIXES_CorrectInvalidTimerID          (0)
#endif

/**
 * <library>fixes.inc</library>
 * <remarks>
 * fixes.inc doesn't need YSI.  YSI doesn't need fixes.inc.  However, they are
 * both written to be aware of each other and adapt accordingly.  For example,
 * fixes.inc uses a special type of ALS hooking which y_hooks can detect and use
 * to call these callbacks in a better order (so-called "pre-hooks").  But if
 * you don't have y_hooks the other version of ALS is very fractionally better.
 * This define can thus be used to guarantee to fixes.inc that YSI doesn't exist
 * and not to use any of the adapted code.  However, if you're wrong the include
 * probably just won't work, the overhead when not using YSI is absolutely tiny,
 * and when using YSI its optimised out.  So, if in doubt - don't use this.
 * </remarks>
 */

#if !defined FIXES_NoYSI
	#define _FIXES_WARNING 14
	#tryinclude "_fixes_settings"
	#undef _FIXES_WARNING
	static _FIXES_SETTING FIXES_NoYSI = 0;
	#define FIXES_NoYSI                          (0)
#elseif _FIXES_IS_UNSET(FIXES_NoYSI)
	#undef FIXES_NoYSI
	static stock FIXES_NoYSI = 2;
	#define FIXES_NoYSI                          (2)
#elseif FIXES_NoYSI
	#undef FIXES_NoYSI
	static stock FIXES_NoYSI = 1;
	#define FIXES_NoYSI                          (1)
#else
	#undef FIXES_NoYSI
	static stock FIXES_NoYSI = 0;
	#define FIXES_NoYSI                          (0)
#endif

/**
 * <library>fixes.inc</library>
 * <remarks>
 * Most vehicles are created with two explicit colours (say <c>5, 6</c>) or two
 * random colours (<c>-1, -1</c>).  It is allowed, but rare, to create a vehicle
 * with one random colour and one fixed colour (<c>-1, 5</c>, <c>9, -1</c> etc).
 * fixes.inc supports this, but it takes a lot more code to fix than the common
 * case of all or nothing.  Thus, having only one random colour is only
 * supported with this explicit setting enabled.
 * </remarks>
 */

#if !defined FIXES_OneRandomVehicleColour
	#if !defined FIXES_OneRandomVehicleColor
		#define _FIXES_WARNING 15
		#tryinclude "_fixes_settings"
		#undef _FIXES_WARNING
		#define FIXES_OneRandomVehicleColor      (0)
		static _FIXES_SETTING FIXES_OneRandomVehicleColour = 0;
		#define FIXES_OneRandomVehicleColour     (0)
	#elseif _FIXES_IS_UNSET(FIXES_OneRandomVehicleColor)
		static stock FIXES_OneRandomVehicleColour = 2;
		#define FIXES_OneRandomVehicleColour     (2)
	#else
		static stock FIXES_OneRandomVehicleColour = FIXES_OneRandomVehicleColor;
		#define FIXES_OneRandomVehicleColour     (FIXES_OneRandomVehicleColor)
	#endif
	#define FIXES_OneRandomVehicleColour         (0)
#elseif _FIXES_IS_UNSET(FIXES_OneRandomVehicleColour)
	#undef FIXES_OneRandomVehicleColour
	static stock FIXES_OneRandomVehicleColour = 2;
	#define FIXES_OneRandomVehicleColour         (2)
#elseif FIXES_OneRandomVehicleColour
	#undef FIXES_OneRandomVehicleColour
	static stock FIXES_OneRandomVehicleColour = 1;
	#define FIXES_OneRandomVehicleColour         (1)
#else
	#undef FIXES_OneRandomVehicleColour
	static stock FIXES_OneRandomVehicleColour = 0;
	#define FIXES_OneRandomVehicleColour         (0)
#endif

/**
 * <library>fixes.inc</library>
 * <remarks>
 * Hide a message at vehicle creation if <c>FIXES_OneRandomVehicleColour</c>
 * is set, but a vehicle is created with only one random colour.
 * </remarks>
 */

#if !defined FIXES_NoVehicleColourMsg
	#if !defined FIXES_NoVehicleColorMsg
		#define _FIXES_WARNING 16
		#tryinclude "_fixes_settings"
		#undef _FIXES_WARNING
		#define FIXES_NoVehicleColorMsg          (0)
		static _FIXES_SETTING FIXES_NoVehicleColourMsg = 0;
		#define FIXES_NoVehicleColourMsg         (0)
	#elseif _FIXES_IS_UNSET(FIXES_NoVehicleColorMsg)
		static stock FIXES_NoVehicleColourMsg = 2;
		#define FIXES_NoVehicleColourMsg         (2)
	#else
		static stock FIXES_NoVehicleColourMsg = FIXES_NoVehicleColorMsg;
		#define FIXES_NoVehicleColourMsg         (FIXES_NoVehicleColorMsg)
	#endif
	#define FIXES_NoVehicleColourMsg             (0)
#elseif _FIXES_IS_UNSET(FIXES_NoVehicleColourMsg)
	#undef FIXES_NoVehicleColourMsg
	static stock FIXES_NoVehicleColourMsg = 2;
	#define FIXES_NoVehicleColourMsg             (2)
#elseif FIXES_NoVehicleColourMsg
	#undef FIXES_NoVehicleColourMsg
	static stock FIXES_NoVehicleColourMsg = 1;
	#define FIXES_NoVehicleColourMsg             (1)
#else
	#undef FIXES_NoVehicleColourMsg
	static stock FIXES_NoVehicleColourMsg = 0;
	#define FIXES_NoVehicleColourMsg             (0)
#endif

/**
 * <library>fixes.inc</library>
 * <remarks>
 * Load several filterscripts until one fails, to determine the number of
 * previously loaded filterscripts.
 * </remarks>
 */

#if !defined FIXES_CountFilterscripts
	#define _FIXES_WARNING 17
	#tryinclude "_fixes_settings"
	#undef _FIXES_WARNING
	static _FIXES_SETTING FIXES_CountFilterscripts = 1;
	#define FIXES_CountFilterscripts             (1)
#elseif _FIXES_IS_UNSET(FIXES_CountFilterscripts)
	#undef FIXES_CountFilterscripts
	static stock FIXES_CountFilterscripts = 2;
	#define FIXES_CountFilterscripts             (2)
#elseif FIXES_CountFilterscripts
	#undef FIXES_CountFilterscripts
	static stock FIXES_CountFilterscripts = 1;
	#define FIXES_CountFilterscripts             (1)
#else
	#undef FIXES_CountFilterscripts
	static stock FIXES_CountFilterscripts = 0;
	#define FIXES_CountFilterscripts             (0)
#endif

/**
 * <library>fixes.inc</library>
 * <remarks>
 * Hide the message about loading filterscripts and the ignorable errors.
 * </remarks>
 */

#if !defined FIXES_NoFilterscriptsMsg
	#define _FIXES_WARNING 17
	#tryinclude "_fixes_settings"
	#undef _FIXES_WARNING
	static _FIXES_SETTING FIXES_NoFilterscriptsMsg = 1;
	#define FIXES_NoFilterscriptsMsg             (1)
#elseif _FIXES_IS_UNSET(FIXES_NoFilterscriptsMsg)
	#undef FIXES_NoFilterscriptsMsg
	static stock FIXES_NoFilterscriptsMsg = 2;
	#define FIXES_NoFilterscriptsMsg             (2)
#elseif FIXES_NoFilterscriptsMsg
	#undef FIXES_NoFilterscriptsMsg
	static stock FIXES_NoFilterscriptsMsg = 1;
	#define FIXES_NoFilterscriptsMsg             (1)
#else
	#undef FIXES_NoFilterscriptsMsg
	static stock FIXES_NoFilterscriptsMsg = 0;
	#define FIXES_NoFilterscriptsMsg             (0)
#endif

/*

      ,ad8888ba,                         88
     d8"'    `"8b                 ,d     ""
    d8'        `8b                88
    88          88  8b,dPPYba,  MM88MMM  88   ,adPPYba,   8b,dPPYba,   ,adPPYba,
    88          88  88P'    "8a   88     88  a8"     "8a  88P'   `"8a  I8[    ""
    Y8,        ,8P  88       d8   88     88  8b       d8  88       88   `"Y8ba,
     Y8a.    .a8P   88b,   ,a8"   88,    88  "8a,   ,a8"  88       88  aa    ]8I
      `"Y8888Y"'    88`YbbdP"'    "Y888  88   `"YbbdP"'   88       88  `"YbbdP"'
                    88
                    88

*/

// We can add server version compiler code here to only compile fixes that apply
// to the version of the includes for which the user is compiling.

// Controls multiple other fixes.
/**
 * <library>fixes.inc</library>
 * <fix name="API">
 *     <problem>
 *         fixes.inc isn't intended to extend the SA:MP API, but has a lot of
 *         information internally that can be useful to other scripts.  By not
 *         exposing this data, we complicate and bloat scripts by requiring them
 *         to re-implement said functionality.
 *     </problem>
 *     <solution>
 *         Expose the data, behind a tightly controlled API.
 *     </solution>
 *     <author href="https://github.com/Y-Less" >Y_Less</author>
 * </fix>
 */

#if !defined FIX_API
	#define _FIXES_WARNING 1
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_API = _FIXES_DEFAULT;
	#define FIX_API                              _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_API)
	#undef FIX_API
	static stock FIX_API = 2;
	#define FIX_API                              (2)
#elseif FIX_API
	#undef FIX_API
	static stock FIX_API = 1;
	#define FIX_API                              (1)
#else
	#undef FIX_API
	static stock FIX_API = 0;
	#define FIX_API                              (0)
#endif

// Controls multiple other fixes.
/**
 * <library>fixes.inc</library>
 * <fix name="Natives">
 *     <problem>
 *         Several natives are included by default, this enables or disables
 *         them all.  Therefore this is an umbrella fix for several fixes.
 *     </problem>
 *     <solution>
 *         Define them.
 *     </solution>
 *     <see>FIX_GetGravity</see>
 *     <see>FIX_gpci</see>
 *     <see>FIX_IsValidVehicle</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 */

#if !defined FIX_Natives
	#define _FIXES_WARNING 2
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_Natives = _FIXES_DEFAULT;
	#define FIX_Natives                          _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_Natives)
	#undef FIX_Natives
	static stock FIX_Natives = 2;
	#define FIX_Natives                          (2)
#elseif FIX_Natives
	#undef FIX_Natives
	static stock FIX_Natives = 1;
	#define FIX_Natives                          (1)
#else
	#undef FIX_Natives
	static stock FIX_Natives = 0;
	#define FIX_Natives                          (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="GetPlayerColour">
 *     <problem>
 *         Returns "0" if "SetPlayerColor" has never been called.
 *     </problem>
 *     <solution>
 *         Call "SetPlayerColor" in "OnPlayerConnect".
 *     </solution>
 *     <see>OnPlayerConnect</see>
 *     <author    >KoczkaHUN</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_GetPlayerColour
		#undef FIX_GetPlayerColour
	#endif
	static stock FIX_GetPlayerColour = 0;
	#define FIX_GetPlayerColour                  (0)
#elseif !defined FIX_GetPlayerColour
	#if defined FIX_GetPlayerColor
		#if _FIXES_IS_UNSET(FIX_GetPlayerColor)
			_FIXES_CONST_PAWNDOC(FIX_GetPlayerColour = 2);
			#define FIX_GetPlayerColour          (2)
		#else
			_FIXES_CONST_PAWNDOC(FIX_GetPlayerColour = FIX_GetPlayerColor);
			#define FIX_GetPlayerColour          (FIX_GetPlayerColor)
		#endif
	#else
		#define _FIXES_WARNING 3
		#tryinclude "_fixes_options"
		#undef _FIXES_WARNING
		static _FIXES_OPTION FIX_GetPlayerColour = _FIXES_DEFAULT;
		#define FIX_GetPlayerColour              _FIXES_DEFAULT
	#endif
#elseif _FIXES_IS_UNSET(FIX_GetPlayerColour)
	#undef FIX_GetPlayerColour
	static stock FIX_GetPlayerColour = 2;
	#define FIX_GetPlayerColour                  (2)
#elseif FIX_GetPlayerColour
	#undef FIX_GetPlayerColour
	static stock FIX_GetPlayerColour = 1;
	#define FIX_GetPlayerColour                  (1)
#else
	#undef FIX_GetPlayerColour
	static stock FIX_GetPlayerColour = 0;
	#define FIX_GetPlayerColour                  (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="FILTERSCRIPT">
 *     <problem>
 *         Despite the fact that is in every new script, many people dont'
 *         define "FILTERSCRIPT" where appropriate.
 *     </problem>
 *     <solution>
 *         Provide an "IS_FILTERSCRIPT" variable (note the naming to
 *         match the original macro).
 *     </solution>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 *     <see>OnFilterScriptInit</see>
 *     <see>OnGameModeInit</see>
 * </fix>
 */

#if !defined FIX_FILTERSCRIPT
	#define _FIXES_WARNING 4
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_FILTERSCRIPT = _FIXES_DEFAULT;
	#define FIX_FILTERSCRIPT                     _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_FILTERSCRIPT)
	#undef FIX_FILTERSCRIPT
	static stock FIX_FILTERSCRIPT = 2;
	#define FIX_FILTERSCRIPT                     (2)
#elseif FIX_FILTERSCRIPT
	#undef FIX_FILTERSCRIPT
	static stock FIX_FILTERSCRIPT = 1;
	#define FIX_FILTERSCRIPT                     (1)
#else
	#undef FIX_FILTERSCRIPT
	static stock FIX_FILTERSCRIPT = 0;
	#define FIX_FILTERSCRIPT                     (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="SpawnPlayer">
 *     <problem>
 *         Kills the player if they are in a vehicle.
 *     </problem>
 *     <solution>
 *         Remove the from the vehicle.
 *     </solution>
 *     <see>FIXES_SpawnPlayer</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_SpawnPlayer
		#undef FIX_SpawnPlayer
	#endif
	static stock FIX_SpawnPlayer = 0;
	#define FIX_SpawnPlayer                      (0)
#elseif !defined FIX_SpawnPlayer
	#define _FIXES_WARNING 5
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_SpawnPlayer = _FIXES_DEFAULT;
	#define FIX_SpawnPlayer                      _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_SpawnPlayer)
	#undef FIX_SpawnPlayer
	static stock FIX_SpawnPlayer = 2;
	#define FIX_SpawnPlayer                      (2)
#elseif FIX_SpawnPlayer
	#undef FIX_SpawnPlayer
	static stock FIX_SpawnPlayer = 1;
	#define FIX_SpawnPlayer                      (1)
#else
	#undef FIX_SpawnPlayer
	static stock FIX_SpawnPlayer = 0;
	#define FIX_SpawnPlayer                      (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="SetPlayerName">
 *     <problem>
 *         Using "SetPlayerName" when the new name only differs from the old
 *         name in case does not alter the name at all.
 *     </problem>
 *     <solution>
 *         Change their name twice - once to "_FIXES TEMP NAME" and then
 *         to the actual required name.
 *     </solution>
 *     <see>OnPlayerConnect</see>
 *     <see>FIXES_SetPlayerName</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 *     <author    href="https://github.com/oscar-broman/" >Slice</author>
 *     <author    href="https://github.com/simonepri/" >simonepri</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_SetPlayerName
		#undef FIX_SetPlayerName
	#endif
	static stock FIX_SetPlayerName = 0;
	#define FIX_SetPlayerName                    (0)
#elseif !defined FIX_SetPlayerName
	#define _FIXES_WARNING 6
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_SetPlayerName = _FIXES_DEFAULT;
	#define FIX_SetPlayerName                    _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_SetPlayerName)
	#undef FIX_SetPlayerName
	static stock FIX_SetPlayerName = 2;
	#define FIX_SetPlayerName                    (2)
#elseif FIX_SetPlayerName
	#undef FIX_SetPlayerName
	static stock FIX_SetPlayerName = 1;
	#define FIX_SetPlayerName                    (1)
#else
	#undef FIX_SetPlayerName
	static stock FIX_SetPlayerName = 0;
	#define FIX_SetPlayerName                    (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="GetPlayerSkin">
 *     <problem>
 *         Returns the new skin after "SetSpawnInfo" is called but before the
 *         player actually respawns to get the new skin.
 *     </problem>
 *     <solution>
 *         Record the skin in "OnPlayerSpawn" and always return that one.
 *
 *     </solution>
 *     <see>OnPlayerSpawn</see>
 *     <see>FIXES_GetPlayerSkin</see>
 *     <see>FIXES_SetPlayerSkin</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_GetPlayerSkin
		#undef FIX_GetPlayerSkin
	#endif
	static stock FIX_GetPlayerSkin = 0;
	#define FIX_GetPlayerSkin                    (0)
#elseif !defined FIX_GetPlayerSkin
	#define _FIXES_WARNING 7
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_GetPlayerSkin = _FIXES_DEFAULT;
	#define FIX_GetPlayerSkin                    _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_GetPlayerSkin)
	#undef FIX_GetPlayerSkin
	static stock FIX_GetPlayerSkin = 2;
	#define FIX_GetPlayerSkin                    (2)
#elseif FIX_GetPlayerSkin
	#undef FIX_GetPlayerSkin
	static stock FIX_GetPlayerSkin = 1;
	#define FIX_GetPlayerSkin                    (1)
#else
	#undef FIX_GetPlayerSkin
	static stock FIX_GetPlayerSkin = 0;
	#define FIX_GetPlayerSkin                    (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="GetWeaponName" fixed="0.3.7">
 *     <problem>
 *         Returns nothing for 18, 44, and 45.
 *     </problem>
 *     <solution>
 *         Return the correct names (<c>Molotov Cocktail</c>, <c>Thermal
 *         Goggles</c>, and <c>Night vision Goggles</c>).
 *     </solution>
 *     <see>FIXES_GetWeaponName</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_GetWeaponName
		#undef FIX_GetWeaponName
	#endif
	static stock FIX_GetWeaponName = 0;
	#define FIX_GetWeaponName                    (0)
#elseif !defined FIX_GetWeaponName
	#define _FIXES_WARNING 8
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_GetWeaponName = _FIXES_DEFAULT;
	#define FIX_GetWeaponName                    _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_GetWeaponName)
	#undef FIX_GetWeaponName
	static stock FIX_GetWeaponName = 2;
	#define FIX_GetWeaponName                    (2)
#elseif FIX_GetWeaponName
	#undef FIX_GetWeaponName
	static stock FIX_GetWeaponName = 1;
	#define FIX_GetWeaponName                    (1)
#else
	#undef FIX_GetWeaponName
	static stock FIX_GetWeaponName = 0;
	#define FIX_GetWeaponName                    (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="SetPlayerWorldBounds">
 *     <problem>
 *         Aiming can bypass the edge.
 *     </problem>
 *     <solution>
 *         Check for the player leaving the area and reset them to their last
 *         good position if they leave the area (aiming or not).
 *     </solution>
 *     <see>OnPlayerUpdate</see>
 *     <see>FIXES_SetPlayerWorldBounds</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_SetPlayerWorldBounds
		#undef FIX_SetPlayerWorldBounds
	#endif
	static stock FIX_SetPlayerWorldBounds = 0;
	#define FIX_SetPlayerWorldBounds             (0)
#elseif !defined FIX_SetPlayerWorldBounds
	#define _FIXES_WARNING 9
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_SetPlayerWorldBounds = _FIXES_DEFAULT;
	#define FIX_SetPlayerWorldBounds             _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_SetPlayerWorldBounds)
	#undef FIX_SetPlayerWorldBounds
	static stock FIX_SetPlayerWorldBounds = 2;
	#define FIX_SetPlayerWorldBounds             (2)
#elseif FIX_SetPlayerWorldBounds
	#undef FIX_SetPlayerWorldBounds
	static stock FIX_SetPlayerWorldBounds = 1;
	#define FIX_SetPlayerWorldBounds             (1)
#else
	#undef FIX_SetPlayerWorldBounds
	static stock FIX_SetPlayerWorldBounds = 0;
	#define FIX_SetPlayerWorldBounds             (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="TogglePlayerControllable">
 *     <problem>
 *         Other players see you moving on the spot.
 *     </problem>
 *     <solution>
 *         Return 0 in OnPlayerUpdate.
 *     </solution>
 *     <see>FIXES_TogglePlayerControllable</see>
 *     <see>OnPlayerUpdate</see>
 *     <author    href="https://github.com/oscar-broman/" >Slice</author>
 *     <post      href="https://sampforum.blast.hk/showthread.php?pid=876854#pid876854" />
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_TogglePlayerControllable
		#undef FIX_TogglePlayerControllable
	#endif
	static stock FIX_TogglePlayerControllable = 0;
	#define FIX_TogglePlayerControllable         (0)
#elseif !defined FIX_TogglePlayerControllable
	#if defined SetObjectMaterial
		#if FIXES_EnableDeprecated
			#define _FIXES_WARNING 10
			#tryinclude "_fixes_options"
			#undef _FIXES_WARNING
			static _FIXES_OPTION FIX_TogglePlayerControllable = FIXES_EnableDeprecated;
		#else
			_FIXES_CONST_PAWNDOC(FIX_TogglePlayerControllable = FIXES_EnableDeprecated);
		#endif
		#define FIX_TogglePlayerControllable     FIXES_EnableDeprecated
	#else
		#define _FIXES_WARNING 10
		#tryinclude "_fixes_options"
		#undef _FIXES_WARNING
		static _FIXES_OPTION FIX_TogglePlayerControllable = _FIXES_DEFAULT;
		#define FIX_TogglePlayerControllable     _FIXES_DEFAULT
	#endif
#elseif _FIXES_IS_UNSET(FIX_TogglePlayerControllable)
	#undef FIX_TogglePlayerControllable
	static stock FIX_TogglePlayerControllable = 2;
	#define FIX_TogglePlayerControllable         (2)
#elseif FIX_TogglePlayerControllable
	#undef FIX_TogglePlayerControllable
	static stock FIX_TogglePlayerControllable = 1;
	#define FIX_TogglePlayerControllable         (1)
#else
	#undef FIX_TogglePlayerControllable
	static stock FIX_TogglePlayerControllable = 0;
	#define FIX_TogglePlayerControllable         (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="HydraSniper">
 *     <problem>
 *         Entering military aircraft with a sniper rifle messes up views.
 *     </problem>
 *     <solution>
 *         Set their armed weapon to fists.
 *     </solution>
 *     <see>OnPlayerStateChange</see>
 *     <see>FIXES_GivePlayerWeapon</see>
 *     <see>FIXES_SetPlayerArmedWeapon</see>
 *     <author    >funky1234</author>
 *     <post      href="https://sampforum.blast.hk/showthread.php?pid=965644#pid965644" />
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_HydraSniper
		#undef FIX_HydraSniper
	#endif
	static stock FIX_HydraSniper = 0;
	#define FIX_HydraSniper                      (0)
#elseif !defined FIX_HydraSniper
	#define _FIXES_WARNING 11
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_HydraSniper = _FIXES_DEFAULT;
	#define FIX_HydraSniper                      _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_HydraSniper)
	#undef FIX_HydraSniper
	static stock FIX_HydraSniper = 2;
	#define FIX_HydraSniper                      (2)
#elseif FIX_HydraSniper
	#undef FIX_HydraSniper
	static stock FIX_HydraSniper = 1;
	#define FIX_HydraSniper                      (1)
#else
	#undef FIX_HydraSniper
	static stock FIX_HydraSniper = 0;
	#define FIX_HydraSniper                      (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="IsPlayerInCheckpoint">
 *     <problem>
 *         Function returns an undefined value if it is called before any other
 *         checkpoint functions are called to initialise the value.
 *     </problem>
 *     <solution>
 *         Call "DisablePlayerCheckpoint" when they connect.
 *     </solution>
 *     <see>OnPlayerConnect</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_IsPlayerInCheckpoint
		#undef FIX_IsPlayerInCheckpoint
	#endif
	static stock FIX_IsPlayerInCheckpoint = 0;
	#define FIX_IsPlayerInCheckpoint             (0)
#elseif !defined FIX_IsPlayerInCheckpoint
	#define _FIXES_WARNING 12
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_IsPlayerInCheckpoint = _FIXES_DEFAULT;
	#define FIX_IsPlayerInCheckpoint             _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_IsPlayerInCheckpoint)
	#undef FIX_IsPlayerInCheckpoint
	static stock FIX_IsPlayerInCheckpoint = 2;
	#define FIX_IsPlayerInCheckpoint             (2)
#elseif FIX_IsPlayerInCheckpoint
	#undef FIX_IsPlayerInCheckpoint
	static stock FIX_IsPlayerInCheckpoint = 1;
	#define FIX_IsPlayerInCheckpoint             (1)
#else
	#undef FIX_IsPlayerInCheckpoint
	static stock FIX_IsPlayerInCheckpoint = 0;
	#define FIX_IsPlayerInCheckpoint             (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="IsPlayerInRaceCheckpoint">
 *     <problem>
 *         Function returns an undefined value if it is called before any other
 *         race checkpoint functions are called to initialise the value.
 *     </problem>
 *     <solution>
 *         Call "DisablePlayerRaceCheckpoint" when they connect.
 *     </solution>
 *     <see>OnPlayerConnect</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_IsPlayerInRaceCheckpoint
		#undef FIX_IsPlayerInRaceCheckpoint
	#endif
	static stock FIX_IsPlayerInRaceCheckpoint = 0;
	#define FIX_IsPlayerInRaceCheckpoint         (0)
#elseif !defined FIX_IsPlayerInRaceCheckpoint
	#define _FIXES_WARNING 13
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_IsPlayerInRaceCheckpoint = _FIXES_DEFAULT;
	#define FIX_IsPlayerInRaceCheckpoint         _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_IsPlayerInRaceCheckpoint)
	#undef FIX_IsPlayerInRaceCheckpoint
	static stock FIX_IsPlayerInRaceCheckpoint = 2;
	#define FIX_IsPlayerInRaceCheckpoint         (2)
#elseif FIX_IsPlayerInRaceCheckpoint
	#undef FIX_IsPlayerInRaceCheckpoint
	static stock FIX_IsPlayerInRaceCheckpoint = 1;
	#define FIX_IsPlayerInRaceCheckpoint         (1)
#else
	#undef FIX_IsPlayerInRaceCheckpoint
	static stock FIX_IsPlayerInRaceCheckpoint = 0;
	#define FIX_IsPlayerInRaceCheckpoint         (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="GetPlayerWeapon">
 *     <problem>
 *         Returns the old value after entering in a vehicle.
 *     </problem>
 *     <solution>
 *         If "SetPlayerArmedWeapon" and other similar functions is called in a
 *         vehicle, store the new value and return that instead.
 *     </solution>
 *     <see>OnPlayerStateChange</see>
 *     <see>FIXES_SetPlayerArmedWeapon</see>
 *     <see>FIXES_GetPlayerWeapon</see>
 *     <see>FIXES_GivePlayerWeapon</see>
 *     <see>FIXES_ResetPlayerWeapons</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 *     <author    href="https://github.com/ronixtey/" >ronixtey</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_GetPlayerWeapon
		#undef FIX_GetPlayerWeapon
	#endif
	static stock FIX_GetPlayerWeapon = 0;
	#define FIX_GetPlayerWeapon                  (0)
#elseif !defined FIX_GetPlayerWeapon
	#define _FIXES_WARNING 14
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_GetPlayerWeapon = _FIXES_DEFAULT;
	#define FIX_GetPlayerWeapon                  _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_GetPlayerWeapon)
	#undef FIX_GetPlayerWeapon
	static stock FIX_GetPlayerWeapon = 2;
	#define FIX_GetPlayerWeapon                  (2)
#elseif FIX_GetPlayerWeapon
	#undef FIX_GetPlayerWeapon
	static stock FIX_GetPlayerWeapon = 1;
	#define FIX_GetPlayerWeapon                  (1)
#else
	#undef FIX_GetPlayerWeapon
	static stock FIX_GetPlayerWeapon = 0;
	#define FIX_GetPlayerWeapon                  (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="PutPlayerInVehicle">
 *     <problem>
 *         If this is used on a passenger the driver of their old vehicle
 *         doesn't see them in their new vehicle.
 *     </problem>
 *     <solution>
 *         Remove them from the vehicle first.
 *     </solution>
 *     <see>OnPlayerStateChange</see>
 *     <see>FIXES_PutPlayerInVehicle</see>
 *     <author    >leong124</author>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 *     <post      href="http://web-old.archive.org/web/20190415184628/https://forum.sa-mp.com/showpost.php?p=1265965" />
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_PutPlayerInVehicle
		#undef FIX_PutPlayerInVehicle
	#endif
	static stock FIX_PutPlayerInVehicle = 0;
	#define FIX_PutPlayerInVehicle               (0)
#elseif !defined FIX_PutPlayerInVehicle
	#define _FIXES_WARNING 15
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_PutPlayerInVehicle = _FIXES_DEFAULT;
	#define FIX_PutPlayerInVehicle               _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_PutPlayerInVehicle)
	#undef FIX_PutPlayerInVehicle
	static stock FIX_PutPlayerInVehicle = 2;
	#define FIX_PutPlayerInVehicle               (2)
#elseif FIX_PutPlayerInVehicle
	#undef FIX_PutPlayerInVehicle
	static stock FIX_PutPlayerInVehicle = 1;
	#define FIX_PutPlayerInVehicle               (1)
#else
	#undef FIX_PutPlayerInVehicle
	static stock FIX_PutPlayerInVehicle = 0;
	#define FIX_PutPlayerInVehicle               (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="KEY_AIM">
 *     <problem>
 *         "KEY_AIM" isn't defined by default.
 *     </problem>
 *     <solution>
 *         Define it.
 *     </solution>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 */

#if !defined FIX_KEY_AIM
	#if defined KEY_AIM
		#if FIXES_EnableDeprecated
			#define _FIXES_WARNING 16
			#tryinclude "_fixes_options"
			#undef _FIXES_WARNING
			static _FIXES_OPTION FIX_KEY_AIM = FIXES_EnableDeprecated;
		#else
			_FIXES_CONST_PAWNDOC(FIX_KEY_AIM = FIXES_EnableDeprecated);
		#endif
		#define FIX_KEY_AIM                      FIXES_EnableDeprecated
	#else
		#define _FIXES_WARNING 16
		#tryinclude "_fixes_options"
		#undef _FIXES_WARNING
		static _FIXES_OPTION FIX_KEY_AIM = _FIXES_DEFAULT;
		#define FIX_KEY_AIM                      _FIXES_DEFAULT
	#endif
#elseif _FIXES_IS_UNSET(FIX_KEY_AIM)
	#undef FIX_KEY_AIM
	static stock FIX_KEY_AIM = 2;
	#define FIX_KEY_AIM                          (2)
#elseif FIX_KEY_AIM
	#undef FIX_KEY_AIM
	static stock FIX_KEY_AIM = 1;
	#define FIX_KEY_AIM                          (1)
#else
	#undef FIX_KEY_AIM
	static stock FIX_KEY_AIM = 0;
	#define FIX_KEY_AIM                          (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="SPECIAL_ACTION_PISSING">
 *     <problem>
 *         "SPECIAL_ACTION_PISSING" isn't defined by default.
 *     </problem>
 *     <solution>
 *         Define it.
 *     </solution>
 *     <author    href="https://github.com/simonepri/" >simonepri</author>
 * </fix>
 */

#if !defined FIX_SPECIAL_ACTION_PISSING
	#if defined SPECIAL_ACTION_PISSING
		#if FIXES_EnableDeprecated
			#define _FIXES_WARNING 17
			#tryinclude "_fixes_options"
			#undef _FIXES_WARNING
			static _FIXES_OPTION FIX_SPECIAL_ACTION_PISSING = FIXES_EnableDeprecated;
		#else
			_FIXES_CONST_PAWNDOC(FIX_SPECIAL_ACTION_PISSING = FIXES_EnableDeprecated);
		#endif
		#define FIX_SPECIAL_ACTION_PISSING       FIXES_EnableDeprecated
	#else
		#define _FIXES_WARNING 17
		#tryinclude "_fixes_options"
		#undef _FIXES_WARNING
		static _FIXES_OPTION FIX_SPECIAL_ACTION_PISSING = _FIXES_DEFAULT;
		#define FIX_SPECIAL_ACTION_PISSING       _FIXES_DEFAULT
	#endif
#elseif _FIXES_IS_UNSET(FIX_SPECIAL_ACTION_PISSING)
	#undef FIX_SPECIAL_ACTION_PISSING
	static stock FIX_SPECIAL_ACTION_PISSING = 2;
	#define FIX_SPECIAL_ACTION_PISSING           (2)
#elseif FIX_SPECIAL_ACTION_PISSING
	#undef FIX_SPECIAL_ACTION_PISSING
	static stock FIX_SPECIAL_ACTION_PISSING = 1;
	#define FIX_SPECIAL_ACTION_PISSING           (1)
#else
	#undef FIX_SPECIAL_ACTION_PISSING
	static stock FIX_SPECIAL_ACTION_PISSING = 0;
	#define FIX_SPECIAL_ACTION_PISSING           (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="IsValidVehicle">
 *     <problem>
 *         "IsValidVehicle" isn't defined by default.
 *     </problem>
 *     <solution>
 *         Define it.
 *     </solution>
 *     <author    href="https://github.com/simonepri/" >simonepri</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_IsValidVehicle
		#undef FIX_IsValidVehicle
	#endif
	static stock FIX_IsValidVehicle = 0;
	#define FIX_IsValidVehicle                   (0)
#elseif !defined FIX_IsValidVehicle
	#if defined IsValidVehicle
		#if FIXES_EnableDeprecated
			#define _FIXES_WARNING 18
			#tryinclude "_fixes_options"
			#undef _FIXES_WARNING
			static _FIXES_OPTION FIX_IsValidVehicle = FIXES_EnableDeprecated;
		#else
			_FIXES_CONST_PAWNDOC(FIX_IsValidVehicle = FIXES_EnableDeprecated);
		#endif
		#define FIX_IsValidVehicle               FIXES_EnableDeprecated
	#else
		#define _FIXES_WARNING 18
		#tryinclude "_fixes_options"
		#undef _FIXES_WARNING
		static _FIXES_OPTION FIX_IsValidVehicle = FIX_Natives;
	#define FIX_IsValidVehicle                   FIX_Natives
	#endif
#elseif _FIXES_IS_UNSET(FIX_IsValidVehicle)
	#undef FIX_IsValidVehicle
	static stock FIX_IsValidVehicle = 2;
	#define FIX_IsValidVehicle                   (2)
#elseif FIX_IsValidVehicle
	#undef FIX_IsValidVehicle
	static stock FIX_IsValidVehicle = 1;
	#define FIX_IsValidVehicle                   (1)
#else
	#undef FIX_IsValidVehicle
	static stock FIX_IsValidVehicle = 0;
	#define FIX_IsValidVehicle                   (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="GetGravity">
 *     <problem>
 *         "GetGravity" isn't defined by default.
 *     </problem>
 *     <solution>
 *         Define it.
 *     </solution>
 *     <author    href="https://github.com/Whitetigerswt" >Whitetiger</author>
 *     <post      href="http://web-old.archive.org/web/20190415184625/https://forum.sa-mp.com/showpost.php?p=1706447" />
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_GetGravity
		#undef FIX_GetGravity
	#endif
	static stock FIX_GetGravity = 0;
	#define FIX_GetGravity                       (0)
#elseif !defined FIX_GetGravity
	#if defined GetGravity
		#if FIXES_EnableDeprecated
			#define _FIXES_WARNING 19
			#tryinclude "_fixes_options"
			#undef _FIXES_WARNING
			static _FIXES_OPTION FIX_GetGravity = FIXES_EnableDeprecated;
		#else
			_FIXES_CONST_PAWNDOC(FIX_GetGravity = FIXES_EnableDeprecated);
		#endif
		#define FIX_GetGravity                   FIXES_EnableDeprecated
	#else
		#define _FIXES_WARNING 19
		#tryinclude "_fixes_options"
		#undef _FIXES_WARNING
		static _FIXES_OPTION FIX_GetGravity = FIX_Natives;
		#define FIX_GetGravity                   FIX_Natives
	#endif
#elseif _FIXES_IS_UNSET(FIX_GetGravity)
	#undef FIX_GetGravity
	static stock FIX_GetGravity = 2;
	#define FIX_GetGravity                       (2)
#elseif FIX_GetGravity
	#undef FIX_GetGravity
	static stock FIX_GetGravity = 1;
	#define FIX_GetGravity                       (1)
#else
	#undef FIX_GetGravity
	static stock FIX_GetGravity = 0;
	#define FIX_GetGravity                       (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="gpci">
 *     <problem>
 *         "gpci" isn't defined by default.
 *     </problem>
 *     <solution>
 *         Define it.
 *     </solution>
 *     <author    href="https://github.com/simonepri/" >simonepri</author>
 *     <post      href="http://pastebin.com/VQSGpbSm" />
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_gpci
		#undef FIX_gpci
	#endif
	static stock FIX_gpci = 0;
	#define FIX_gpci                          (0)
#elseif !defined FIX_gpci
	#if defined gpci
		#if FIXES_EnableDeprecated
			#define _FIXES_WARNING 20
			#tryinclude "_fixes_options"
			#undef _FIXES_WARNING
			static _FIXES_OPTION FIX_gpci = FIXES_EnableDeprecated;
		#else
			_FIXES_CONST_PAWNDOC(FIX_gpci = FIXES_EnableDeprecated);
		#endif
		#define FIX_gpci                         FIXES_EnableDeprecated
	#else
		#define _FIXES_WARNING 20
		#tryinclude "_fixes_options"
		#undef _FIXES_WARNING
		static _FIXES_OPTION FIX_gpci = FIX_Natives;
		#define FIX_gpci                         FIX_Natives
	#endif
#elseif _FIXES_IS_UNSET(FIX_gpci)
	#undef FIX_gpci
	static stock FIX_gpci = 2;
	#define FIX_gpci                             (2)
#elseif FIX_gpci
	#undef FIX_gpci
	static stock FIX_gpci = 1;
	#define FIX_gpci                             (1)
#else
	#undef FIX_gpci
	static stock FIX_gpci = 0;
	#define FIX_gpci                             (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="WEAPONS">
 *     <problem>
 *         Some weapons are not defined by default.
 *     </problem>
 *     <solution>
 *         Define it.
 *     </solution>
 *     <author    href="https://github.com/ziggi" >ziggi</author>
 * </fix>
 */

#if !defined FIX_WEAPONS
	#if defined WEAPON_FIST
		#if FIXES_EnableDeprecated
			#define _FIXES_WARNING 21
			#tryinclude "_fixes_options"
			#undef _FIXES_WARNING
			static _FIXES_OPTION FIX_WEAPONS = FIXES_EnableDeprecated;
		#else
			_FIXES_CONST_PAWNDOC(FIX_WEAPONS = FIXES_EnableDeprecated);
		#endif
		#define FIX_WEAPONS                      FIXES_EnableDeprecated
	#else
		#define _FIXES_WARNING 21
		#tryinclude "_fixes_options"
		#undef _FIXES_WARNING
		static _FIXES_OPTION FIX_WEAPONS = _FIXES_DEFAULT;
		#define FIX_WEAPONS                      _FIXES_DEFAULT
	#endif
#elseif _FIXES_IS_UNSET(FIX_WEAPONS)
	#undef FIX_WEAPONS
	static stock FIX_WEAPONS = 2;
	#define FIX_WEAPONS                          (2)
#elseif FIX_WEAPONS
	#undef FIX_WEAPONS
	static stock FIX_WEAPONS = 1;
	#define FIX_WEAPONS                          (1)
#else
	#undef FIX_WEAPONS
	static stock FIX_WEAPONS = 0;
	#define FIX_WEAPONS                          (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="BODYPARTS">
 *     <problem>
 *         The bodyparts to be used in OnPlayer(Take/Give)Damage are not defined
 *         by default
 *     </problem>
 *     <solution>
 *         Define it.
 *     </solution>
 *     <author    href="https://github.com/Whitetigerswt" >Whitetiger</author>
 * </fix>
 */

#if !defined FIX_BODYPARTS
	#if defined BODY_PART_LEFT_ARM
		#if FIXES_EnableDeprecated
			#define _FIXES_WARNING 22
			#tryinclude "_fixes_options"
			#undef _FIXES_WARNING
			static _FIXES_OPTION FIX_BODYPARTS = FIXES_EnableDeprecated;
		#else
			_FIXES_CONST_PAWNDOC(FIX_BODYPARTS = FIXES_EnableDeprecated);
		#endif
		#define FIX_BODYPARTS                    FIXES_EnableDeprecated
	#else
		#define _FIXES_WARNING 22
		#tryinclude "_fixes_options"
		#undef _FIXES_WARNING
		static _FIXES_OPTION FIX_BODYPARTS = _FIXES_DEFAULT;
		#define FIX_BODYPARTS                    _FIXES_DEFAULT
	#endif
#elseif _FIXES_IS_UNSET(FIX_BODYPARTS)
	#undef FIX_BODYPARTS
	static stock FIX_BODYPARTS = 2;
	#define FIX_BODYPARTS                        (2)
#elseif FIX_BODYPARTS
	#undef FIX_BODYPARTS
	static stock FIX_BODYPARTS = 1;
	#define FIX_BODYPARTS                        (1)
#else
	#undef FIX_BODYPARTS
	static stock FIX_BODYPARTS = 0;
	#define FIX_BODYPARTS                        (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="CAMERAMODES">
 *     <problem>
 *         The camera modes for GetPlayerCameraMode are not defined by default.
 *     </problem>
 *     <solution>
 *         Define it.
 *     </solution>
 *     <author    href="https://github.com/Whitetigerswt" >Whitetiger</author>
 *     <post      href="https://sampforum.blast.hk/showthread.php?tid=271586&amp;pid=1309730#pid1309730" />
 * </fix>
 */

#if !defined FIX_CAMERAMODES
	#if defined CAM_MODE_NONE
		#if FIXES_EnableDeprecated
			#define _FIXES_WARNING 23
			#tryinclude "_fixes_options"
			#undef _FIXES_WARNING
			static _FIXES_OPTION FIX_CAMERAMODES = FIXES_EnableDeprecated;
		#else
			_FIXES_CONST_PAWNDOC(FIX_CAMERAMODES = FIXES_EnableDeprecated);
		#endif
		#define FIX_CAMERAMODES                  FIXES_EnableDeprecated
	#else
		#define _FIXES_WARNING 23
		#tryinclude "_fixes_options"
		#undef _FIXES_WARNING
		static _FIXES_OPTION FIX_CAMERAMODES = _FIXES_DEFAULT;
		#define FIX_CAMERAMODES                  _FIXES_DEFAULT
	#endif
#elseif _FIXES_IS_UNSET(FIX_CAMERAMODES)
	#undef FIX_CAMERAMODES
	static stock FIX_CAMERAMODES = 2;
	#define FIX_CAMERAMODES                      (2)
#elseif FIX_CAMERAMODES
	#undef FIX_CAMERAMODES
	static stock FIX_CAMERAMODES = 1;
	#define FIX_CAMERAMODES                      (1)
#else
	#undef FIX_CAMERAMODES
	static stock FIX_CAMERAMODES = 0;
	#define FIX_CAMERAMODES                      (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="DriveBy">
 *     <problem>
 *         If you press KEY_CROUCH while you're passenger and if you are armed,
 *         the player start to aim; if you repress KEY_CROUCH the player don't
 *         return in vehicle.
 *     </problem>
 *     <solution>
 *         Apply the animation to return the player in the vehicle.
 *     </solution>
 *     <see>OnPlayerKeyStateChange</see>
 *     <author    href="https://github.com/simonepri/" >simonepri</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_DriveBy
		#undef FIX_DriveBy
	#endif
	static stock FIX_DriveBy = 0;
	#define FIX_DriveBy                          (0)
#elseif !defined FIX_DriveBy
	#define _FIXES_WARNING 24
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_DriveBy = _FIXES_DEFAULT;
	#define FIX_DriveBy                          _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_DriveBy)
	#undef FIX_DriveBy
	static stock FIX_DriveBy = 2;
	#define FIX_DriveBy                          (2)
#elseif FIX_DriveBy
	#undef FIX_DriveBy
	static stock FIX_DriveBy = 1;
	#define FIX_DriveBy                          (1)
#else
	#undef FIX_DriveBy
	static stock FIX_DriveBy = 0;
	#define FIX_DriveBy                          (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="SilentTeleport">
 *     <problem>
 *         Player teleports silently while trying to enter a vehicle as that
 *         vehicle teleports/changes original interior.
 *     </problem>
 *     <solution>
 *         Stop the player from teleporting by using 'ClearAnimations' before
 *         the teleport happens.
 *     </solution>
 *	   <see>OnPlayerEnterVehicle</see>
 *	   <see>OnPlayerInteriorChange</see>
 *     <author    href="https://github.com/RogueDrifter/" >RogueDrifter</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_SilentTeleport
		#undef FIX_SilentTeleport
	#endif
	static stock FIX_SilentTeleport = 0;
	#define FIX_SilentTeleport                   (0)
#elseif !defined FIX_SilentTeleport
	#define _FIXES_WARNING 25
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_SilentTeleport = _FIXES_DEFAULT;
	#define FIX_SilentTeleport                   _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_SilentTeleport)
	#undef FIX_SilentTeleport
	static stock FIX_SilentTeleport = 2;
	#define FIX_SilentTeleport                   (2)
#elseif FIX_SilentTeleport
	#undef FIX_SilentTeleport
	static stock FIX_SilentTeleport = 1;
	#define FIX_SilentTeleport                   (1)
#else
	#undef FIX_SilentTeleport
	static stock FIX_SilentTeleport = 0;
	#define FIX_SilentTeleport                   (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="SetPlayerCheckpoint">
 *     <problem>
 *         If a checkpoint is already set it will use the size of that
 *         checkpoint instead of the new one.
 *     </problem>
 *     <solution>
 *         Call "DisablePlayerCheckpoint" before setting the checkpoint.
 *     </solution>
 *     <see>FIXES_SetPlayerCheckpoint</see>
 *     <author    href="https://github.com/ziggi/" >ziggi</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_SetPlayerCheckpoint
		#undef FIX_SetPlayerCheckpoint
	#endif
	static stock FIX_SetPlayerCheckpoint = 0;
	#define FIX_SetPlayerCheckpoint              (0)
#elseif !defined FIX_SetPlayerCheckpoint
	#define _FIXES_WARNING 26
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_SetPlayerCheckpoint = _FIXES_DEFAULT;
	#define FIX_SetPlayerCheckpoint              _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_SetPlayerCheckpoint)
	#undef FIX_SetPlayerCheckpoint
	static stock FIX_SetPlayerCheckpoint = 2;
	#define FIX_SetPlayerCheckpoint              (2)
#elseif FIX_SetPlayerCheckpoint
	#undef FIX_SetPlayerCheckpoint
	static stock FIX_SetPlayerCheckpoint = 1;
	#define FIX_SetPlayerCheckpoint              (1)
#else
	#undef FIX_SetPlayerCheckpoint
	static stock FIX_SetPlayerCheckpoint = 0;
	#define FIX_SetPlayerCheckpoint              (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="SetPlayerRaceCheckpoint">
 *     <problem>
 *         If a checkpoint is already set it will use the size of that
 *         checkpoint instead of the new one.
 *     </problem>
 *     <solution>
 *         Call "DisablePlayerRaceCheckpoint" before setting the checkpoint.
 *     </solution>
 *     <see>FIXES_SetPlayerRaceCheckpoint</see>
 *     <author    href="https://github.com/ziggi/" >ziggi</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_SetPlayerRaceCheckpoint
		#undef FIX_SetPlayerRaceCheckpoint
	#endif
	static stock FIX_SetPlayerRaceCheckpoint = 0;
	#define FIX_SetPlayerRaceCheckpoint          (0)
#elseif !defined FIX_SetPlayerRaceCheckpoint
	#define _FIXES_WARNING 27
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_SetPlayerRaceCheckpoint = _FIXES_DEFAULT;
	#define FIX_SetPlayerRaceCheckpoint          _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_SetPlayerRaceCheckpoint)
	#undef FIX_SetPlayerRaceCheckpoint
	static stock FIX_SetPlayerRaceCheckpoint = 2;
	#define FIX_SetPlayerRaceCheckpoint          (2)
#elseif FIX_SetPlayerRaceCheckpoint
	#undef FIX_SetPlayerRaceCheckpoint
	static stock FIX_SetPlayerRaceCheckpoint = 1;
	#define FIX_SetPlayerRaceCheckpoint          (1)
#else
	#undef FIX_SetPlayerRaceCheckpoint
	static stock FIX_SetPlayerRaceCheckpoint = 0;
	#define FIX_SetPlayerRaceCheckpoint          (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="TextDrawCreate">
 *     <problem>
 *         Crashes on a blank string.
 *     </problem>
 *     <solution>
 *         Intercept blank strings.
 *     </solution>
 *     <see>FIXES_TextDrawCreate</see>
 *     <author    >wups</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_TextDrawCreate
		#undef FIX_TextDrawCreate
	#endif
	static stock FIX_TextDrawCreate = 0;
	#define FIX_TextDrawCreate                   (0)
#elseif !defined FIX_TextDrawCreate
	#define _FIXES_WARNING 28
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_TextDrawCreate = _FIXES_DEFAULT;
	#define FIX_TextDrawCreate                   _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_TextDrawCreate)
	#undef FIX_TextDrawCreate
	static stock FIX_TextDrawCreate = 2;
	#define FIX_TextDrawCreate                   (2)
#elseif FIX_TextDrawCreate
	#undef FIX_TextDrawCreate
	static stock FIX_TextDrawCreate = 1;
	#define FIX_TextDrawCreate                   (1)
#else
	#undef FIX_TextDrawCreate
	static stock FIX_TextDrawCreate = 0;
	#define FIX_TextDrawCreate                   (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="AttachTrailerToVehicle">
 *     <problem>
 *         When trailerid is equal to vehicleid and passenger is in vehicleid,
 *         it starts spinning.
 *     </problem>
 *     <solution>
 *         Check if trailerid and vehicleid are equal.
 *     </solution>
 *     <see>FIX_AttachTrailerToVehicle</see>
 *     <author    href="https://github.com/Mergevos/" >Mergevos</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_AttachTrailerToVehicle
		#undef FIX_AttachTrailerToVehicle
	#endif
	static stock FIX_AttachTrailerToVehicle = 0;
	#define FIX_AttachTrailerToVehicle           (0)
#elseif !defined FIX_AttachTrailerToVehicle
	#define _FIXES_WARNING 29
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_AttachTrailerToVehicle = _FIXES_DEFAULT;
	#define FIX_AttachTrailerToVehicle           _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_AttachTrailerToVehicle)
	#undef FIX_AttachTrailerToVehicle
	static stock FIX_AttachTrailerToVehicle = 2;
	#define FIX_AttachTrailerToVehicle           (2)
#elseif FIX_AttachTrailerToVehicle
	#undef FIX_AttachTrailerToVehicle
	static stock FIX_AttachTrailerToVehicle = 1;
	#define FIX_AttachTrailerToVehicle           (1)
#else
	#undef FIX_AttachTrailerToVehicle
	static stock FIX_AttachTrailerToVehicle = 0;
	#define FIX_AttachTrailerToVehicle           (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="GetVehicleComponentInSlot">
 *     <problem>
 *         The function GetVehicleComponentInSlot doesn't work for
 *         <c>CARMODTYPE_STEREO</c>.  Both front bull bars and front bumper
 *         components are saved in the <c>CARMODTYPE_FRONT_BUMPER</c> slot.  If
 *         a vehicle has both of them installed, this function will only return
 *         the one which was installed last.  Both rear bull bars and rear
 *         bumper components are saved in the <c>CARMODTYPE_REAR_BUMPER</c>
 *         slot.  If a vehicle has both of them installed this function will
 *         only return the one which was installed last.
 *     </problem>
 *     <solution>
 *         Hook functions and store components. This uses some code from vSync
 *         library.
 *     </solution>
 *     <see>FIXES_GetVehicleComponentInSlot</see>
 *     <author    href="https://github.com/Mergevos/" >Mergevos</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_GetVehicleComponentInSlot
		#undef FIX_GetVehicleComponentInSlot
	#endif
	static stock FIX_GetVehicleComponentInSlot = 0;
	#define FIX_GetVehicleComponentInSlot        (0)
#elseif !defined FIX_GetVehicleComponentInSlot
	#define _FIXES_WARNING 30
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_GetVehicleComponentInSlot = _FIXES_DEFAULT;
	#define FIX_GetVehicleComponentInSlot        _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_GetVehicleComponentInSlot)
	#undef FIX_GetVehicleComponentInSlot
	static stock FIX_GetVehicleComponentInSlot = 2;
	#define FIX_GetVehicleComponentInSlot        (2)
#elseif FIX_GetVehicleComponentInSlot
	#undef FIX_GetVehicleComponentInSlot
	static stock FIX_GetVehicleComponentInSlot = 1;
	#define FIX_GetVehicleComponentInSlot        (1)
#else
	#undef FIX_GetVehicleComponentInSlot
	static stock FIX_GetVehicleComponentInSlot = 0;
	#define FIX_GetVehicleComponentInSlot        (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="TextDrawCreate_2">
 *     <problem>
 *         If the last character in the text is a space (" "), the text will all
 *         be blank.
 *     </problem>
 *     <solution>
 *         Remove space characters from the end of the string.
 *     </solution>
 *     <see>FIXES_TextDrawCreate</see>
 *     <author    href="https://github.com/ziggi/" >ziggi</author>
 *     <post      href="https://github.com/Open-GTO/sa-mp-fixes/issues/55" />
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_TextDrawCreate_2
		#undef FIX_TextDrawCreate_2
	#endif
	static stock FIX_TextDrawCreate_2 = 0;
	#define FIX_TextDrawCreate_2                 (0)
#elseif !defined FIX_TextDrawCreate_2
	#define _FIXES_WARNING 31
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_TextDrawCreate_2 = _FIXES_DEFAULT;
	#define FIX_TextDrawCreate_2                 _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_TextDrawCreate_2)
	#undef FIX_TextDrawCreate_2
	static stock FIX_TextDrawCreate_2 = 2;
	#define FIX_TextDrawCreate_2                 (2)
#elseif FIX_TextDrawCreate_2
	#undef FIX_TextDrawCreate_2
	static stock FIX_TextDrawCreate_2 = 1;
	#define FIX_TextDrawCreate_2                 (1)
#else
	#undef FIX_TextDrawCreate_2
	static stock FIX_TextDrawCreate_2 = 0;
	#define FIX_TextDrawCreate_2                 (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="TextDrawSetString">
 *     <problem>
 *         Crashes on a blank string and size greater than 1024.
 *     </problem>
 *     <solution>
 *         Intercept blank strings and truncate long strings.
 *     </solution>
 *     <see>FIXES_TextDrawSetString</see>
 *     <author    >TomTrox</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_TextDrawSetString
		#undef FIX_TextDrawSetString
	#endif
	static stock FIX_TextDrawSetString = 0;
	#define FIX_TextDrawSetString                (0)
#elseif !defined FIX_TextDrawSetString
	#define _FIXES_WARNING 32
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_TextDrawSetString = _FIXES_DEFAULT;
	#define FIX_TextDrawSetString                _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_TextDrawSetString)
	#undef FIX_TextDrawSetString
	static stock FIX_TextDrawSetString = 2;
	#define FIX_TextDrawSetString                (2)
#elseif FIX_TextDrawSetString
	#undef FIX_TextDrawSetString
	static stock FIX_TextDrawSetString = 1;
	#define FIX_TextDrawSetString                (1)
#else
	#undef FIX_TextDrawSetString
	static stock FIX_TextDrawSetString = 0;
	#define FIX_TextDrawSetString                (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="TextDrawSetString_2">
 *     <problem>
 *         If the last character in the text is a space (" "), the text will all
 *         be blank.
 *     </problem>
 *     <solution>
 *         Remove space characters from the end of the string.
 *     </solution>
 *     <see>FIXES_TextDrawSetString</see>
 *     <author    href="https://github.com/ziggi/" >ziggi</author>
 *     <post      href="https://github.com/Open-GTO/sa-mp-fixes/issues/55" />
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_TextDrawSetString_2
		#undef FIX_TextDrawSetString_2
	#endif
	static stock FIX_TextDrawSetString_2 = 0;
	#define FIX_TextDrawSetString_2              (0)
#elseif !defined FIX_TextDrawSetString_2
	#define _FIXES_WARNING 33
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_TextDrawSetString_2 = _FIXES_DEFAULT;
	#define FIX_TextDrawSetString_2              _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_TextDrawSetString_2)
	#undef FIX_TextDrawSetString_2
	static stock FIX_TextDrawSetString_2 = 2;
	#define FIX_TextDrawSetString_2              (2)
#elseif FIX_TextDrawSetString_2
	#undef FIX_TextDrawSetString_2
	static stock FIX_TextDrawSetString_2 = 1;
	#define FIX_TextDrawSetString_2              (1)
#else
	#undef FIX_TextDrawSetString_2
	static stock FIX_TextDrawSetString_2 = 0;
	#define FIX_TextDrawSetString_2              (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="AllowInteriorWeapons">
 *     <problem>
 *         Does nothing.
 *     </problem>
 *     <solution>
 *         Set the player's weapon to fists in an interior.
 *     </solution>
 *     <see>FIXES_AllowInteriorWeapons</see>
 *     <see>OnGameModeInit</see>
 *     <see>OnPlayerUpdate</see>
 *     <author    >KoczkaHUN</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_AllowInteriorWeapons
		#undef FIX_AllowInteriorWeapons
	#endif
	static stock FIX_AllowInteriorWeapons = 0;
	#define FIX_AllowInteriorWeapons             (0)
#elseif !defined FIX_AllowInteriorWeapons
	#define _FIXES_WARNING 34
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_AllowInteriorWeapons = _FIXES_DEFAULT;
	#define FIX_AllowInteriorWeapons             _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_AllowInteriorWeapons)
	#undef FIX_AllowInteriorWeapons
	static stock FIX_AllowInteriorWeapons = 2;
	#define FIX_AllowInteriorWeapons             (2)
#elseif FIX_AllowInteriorWeapons
	#undef FIX_AllowInteriorWeapons
	static stock FIX_AllowInteriorWeapons = 1;
	#define FIX_AllowInteriorWeapons             (1)
#else
	#undef FIX_AllowInteriorWeapons
	static stock FIX_AllowInteriorWeapons = 0;
	#define FIX_AllowInteriorWeapons             (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="OnPlayerEnterVehicle">
 *     <problem>
 *         Crashes other players when people enter an invalid seat.
 *     </problem>
 *     <solution>
 *         Desync the people with invalid seats.
 *     </solution>
 *     <see>OnPlayerStateChange</see>
 *     <see>OnPlayerUpdate</see>
 *     <author    >RyDeR`</author>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 *     <author    href="https://github.com/NexiusTailer">NexiusTailer</author>
 *     <post      href="http://web-old.archive.org/web/20190415184630/https://forum.sa-mp.com/showpost.php?p=1410296" />
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_OnPlayerEnterVehicle
		#undef FIX_OnPlayerEnterVehicle
	#endif
	static stock FIX_OnPlayerEnterVehicle = 0;
	#define FIX_OnPlayerEnterVehicle             (0)
#elseif !defined FIX_OnPlayerEnterVehicle
	#if defined OnPlayerClickMap
		#if FIXES_EnableDeprecated
			#define _FIXES_WARNING 35
			#tryinclude "_fixes_options"
			#undef _FIXES_WARNING
			static _FIXES_OPTION FIX_OnPlayerEnterVehicle = FIXES_EnableDeprecated;
		#else
			_FIXES_CONST_PAWNDOC(FIX_OnPlayerEnterVehicle = FIXES_EnableDeprecated);
		#endif
		#define FIX_OnPlayerEnterVehicle         FIXES_EnableDeprecated
	#else
		#define _FIXES_WARNING 35
		#tryinclude "_fixes_options"
		#undef _FIXES_WARNING
		static _FIXES_OPTION FIX_OnPlayerEnterVehicle = _FIXES_DEFAULT;
		#define FIX_OnPlayerEnterVehicle         _FIXES_DEFAULT
	#endif
#elseif _FIXES_IS_UNSET(FIX_OnPlayerEnterVehicle)
	#undef FIX_OnPlayerEnterVehicle
	static stock FIX_OnPlayerEnterVehicle = 2;
	#define FIX_OnPlayerEnterVehicle             (2)
#elseif FIX_OnPlayerEnterVehicle
	#undef FIX_OnPlayerEnterVehicle
	static stock FIX_OnPlayerEnterVehicle = 1;
	#define FIX_OnPlayerEnterVehicle             (1)
#else
	#undef FIX_OnPlayerEnterVehicle
	static stock FIX_OnPlayerEnterVehicle = 0;
	#define FIX_OnPlayerEnterVehicle             (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="OnPlayerEnterVehicle_2">
 *     <problem>
 *         Crashes the server when hacks enter an invalid vehicle.
 *     </problem>
 *     <solution>
 *         Desync the people with invalid vehicles.
 *     </solution>
 *     <see>OnPlayerEnterVehicle</see>
 *     <author    >im</author>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_OnPlayerEnterVehicle_2
		#undef FIX_OnPlayerEnterVehicle_2
	#endif
	static stock FIX_OnPlayerEnterVehicle_2 = 0;
	#define FIX_OnPlayerEnterVehicle_2           (0)
#elseif !defined FIX_OnPlayerEnterVehicle_2
	#define _FIXES_WARNING 36
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_OnPlayerEnterVehicle_2 = _FIXES_DEFAULT;
	#define FIX_OnPlayerEnterVehicle_2           _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_OnPlayerEnterVehicle_2)
	#undef FIX_OnPlayerEnterVehicle_2
	static stock FIX_OnPlayerEnterVehicle_2 = 2;
	#define FIX_OnPlayerEnterVehicle_2           (2)
#elseif FIX_OnPlayerEnterVehicle_2
	#undef FIX_OnPlayerEnterVehicle_2
	static stock FIX_OnPlayerEnterVehicle_2 = 1;
	#define FIX_OnPlayerEnterVehicle_2           (1)
#else
	#undef FIX_OnPlayerEnterVehicle_2
	static stock FIX_OnPlayerEnterVehicle_2 = 0;
	#define FIX_OnPlayerEnterVehicle_2           (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="OnPlayerEnterVehicle_3">
 *     <problem>
 *         No player animation when trying to enter the driver door of a locked
 *         vehicle
 *     </problem>
 *     <solution>
 *         Leave the door unlocked and activate an animation when the player
 *         attemps to enter a 'locked' vehicle.
 *     </solution>
 *     <see>OnPlayerEnterVehicle</see>
 *     <author    href="https://github.com/ziggi" >ziggi</author>
 *     <author    href="https://github.com/rt-2" >rt-2</author>
 *     <post      href="https://sampforum.blast.hk/showthread.php?tid=560019" />
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_OnPlayerEnterVehicle_3
		#undef FIX_OnPlayerEnterVehicle_3
	#endif
	static stock FIX_OnPlayerEnterVehicle_3 = 0;
	#define FIX_OnPlayerEnterVehicle_3           (0)
#elseif !defined FIX_OnPlayerEnterVehicle_3
	#define _FIXES_WARNING 37
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_OnPlayerEnterVehicle_3 = _FIXES_DEFAULT;
	#define FIX_OnPlayerEnterVehicle_3           _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_OnPlayerEnterVehicle_3)
	#undef FIX_OnPlayerEnterVehicle_3
	static stock FIX_OnPlayerEnterVehicle_3 = 2;
	#define FIX_OnPlayerEnterVehicle_3           (2)
#elseif FIX_OnPlayerEnterVehicle_3
	#undef FIX_OnPlayerEnterVehicle_3
	static stock FIX_OnPlayerEnterVehicle_3 = 1;
	#define FIX_OnPlayerEnterVehicle_3           (1)
#else
	#undef FIX_OnPlayerEnterVehicle_3
	static stock FIX_OnPlayerEnterVehicle_3 = 0;
	#define FIX_OnPlayerEnterVehicle_3           (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="AllowTeleport">
 *     <problem>
 *         0.3dRC9 removed "AllowPlayerTeleport" and "AllowAdminTeleport" in
 *         favour of "OnPlayerClickMap".  Some scripts used the old code and.
 *     </problem>
 *     <solution>
 *         Teleport the player in "OnPlayerClickMap".
 *     </solution>
 *     <see>OnPlayerClickMap</see>
 *     <see>FIXES_AllowPlayerTeleport</see>
 *     <see>FIXES_AllowAdminTeleport</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_AllowTeleport
		#undef FIX_AllowTeleport
	#endif
	static stock FIX_AllowTeleport = 0;
	#define FIX_AllowTeleport                    (0)
#elseif !defined FIX_AllowTeleport
	#if defined OnPlayerClickMap
		#define _FIXES_WARNING 38
		#tryinclude "_fixes_options"
		#undef _FIXES_WARNING
		static _FIXES_OPTION FIX_AllowTeleport = _FIXES_DEFAULT;
		#define FIX_AllowTeleport                _FIXES_DEFAULT
	#else
		#if FIXES_EnableDeprecated
			#define _FIXES_WARNING 38
			#tryinclude "_fixes_options"
			#undef _FIXES_WARNING
			static _FIXES_OPTION FIX_AllowTeleport = FIXES_EnableDeprecated;
		#else
			_FIXES_CONST_PAWNDOC(FIX_AllowTeleport = FIXES_EnableDeprecated);
		#endif
		#define FIX_AllowTeleport                FIXES_EnableDeprecated
	#endif
#elseif _FIXES_IS_UNSET(FIX_AllowTeleport)
	#undef FIX_AllowTeleport
	static stock FIX_AllowTeleport = 2;
	#define FIX_AllowTeleport                    (2)
#elseif FIX_AllowTeleport
	#undef FIX_AllowTeleport
	static stock FIX_AllowTeleport = 1;
	#define FIX_AllowTeleport                    (1)
#else
	#undef FIX_AllowTeleport
	static stock FIX_AllowTeleport = 0;
	#define FIX_AllowTeleport                    (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="SetPlayerSpecialAction">
 *     <problem>
 *         Removing jetpacks from players by setting their special action to 0
 *         causes the sound to stay until death.
 *     </problem>
 *     <solution>
 *         Call "ClearAnimations" before "SetPlayerSpecialAction".
 *     </solution>
 *     <see>FIXES_SetPlayerSpecialAction</see>
 *     <author    >MP2</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_SetPlayerSpecialAction
		#undef FIX_SetPlayerSpecialAction
	#endif
	static stock FIX_SetPlayerSpecialAction = 0;
	#define FIX_SetPlayerSpecialAction           (0)
#elseif !defined FIX_SetPlayerSpecialAction
	#define _FIXES_WARNING 39
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_SetPlayerSpecialAction = _FIXES_DEFAULT;
	#define FIX_SetPlayerSpecialAction           _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_SetPlayerSpecialAction)
	#undef FIX_SetPlayerSpecialAction
	static stock FIX_SetPlayerSpecialAction = 2;
	#define FIX_SetPlayerSpecialAction           (2)
#elseif FIX_SetPlayerSpecialAction
	#undef FIX_SetPlayerSpecialAction
	static stock FIX_SetPlayerSpecialAction = 1;
	#define FIX_SetPlayerSpecialAction           (1)
#else
	#undef FIX_SetPlayerSpecialAction
	static stock FIX_SetPlayerSpecialAction = 0;
	#define FIX_SetPlayerSpecialAction           (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="ClearAnimations">
 *     <problem>
 *         Use ClearAnimation while you are in a vehicle cause the player exit
 *         from it.
 *     </problem>
 *     <solution>
 *         Apply an animation instead of clear animation.
 *     </solution>
 *     <see>FIXES_ClearAnimations</see>
 *     <author    href="https://github.com/simonepri/" >simonepri</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_ClearAnimations
		#undef FIX_ClearAnimations
	#endif
	static stock FIX_ClearAnimations = 0;
	#define FIX_ClearAnimations                  (0)
#elseif !defined FIX_ClearAnimations
	#define _FIXES_WARNING 40
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_ClearAnimations = _FIXES_DEFAULT;
	#define FIX_ClearAnimations                  _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_ClearAnimations)
	#undef FIX_ClearAnimations
	static stock FIX_ClearAnimations = 2;
	#define FIX_ClearAnimations                  (2)
#elseif FIX_ClearAnimations
	#undef FIX_ClearAnimations
	static stock FIX_ClearAnimations = 1;
	#define FIX_ClearAnimations                  (1)
#else
	#undef FIX_ClearAnimations
	static stock FIX_ClearAnimations = 0;
	#define FIX_ClearAnimations                  (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="ClearAnimations_2">
 *     <problem>
 *         ClearAnimations doesn't do anything when the animation ends if we
 *         pass 1 for the freeze parameter in ApplyAnimation.
 *     </problem>
 *     <solution>
 *         Apply an idle animation for stop and then use ClearAnimation.
 *     </solution>
 *     <see>FIXES_ClearAnimations</see>
 *     <author    href="https://github.com/simonepri/" >simonepri</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_ClearAnimations_2
		#undef FIX_ClearAnimations_2
	#endif
	static stock FIX_ClearAnimations_2 = 0;
	#define FIX_ClearAnimations_2                (0)
#elseif !defined FIX_ClearAnimations_2
	#define _FIXES_WARNING 41
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_ClearAnimations_2 = _FIXES_DEFAULT;
	#define FIX_ClearAnimations_2                _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_ClearAnimations_2)
	#undef FIX_ClearAnimations_2
	static stock FIX_ClearAnimations_2 = 2;
	#define FIX_ClearAnimations_2                (2)
#elseif FIX_ClearAnimations_2
	#undef FIX_ClearAnimations_2
	static stock FIX_ClearAnimations_2 = 1;
	#define FIX_ClearAnimations_2                (1)
#else
	#undef FIX_ClearAnimations_2
	static stock FIX_ClearAnimations_2 = 0;
	#define FIX_ClearAnimations_2                (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="GangZoneCreate">
 *     <problem>
 *         Gang zones bug on the main map for players at certain angles relative
 *         to them.
 *     </problem>
 *     <solution>
 *         Set a non floating value for the gang zone co-ordinate.
 *     </solution>
 *     <see>FIXES_GangZoneCreate</see>
 *     <author    href="https://github.com/simonepri/" >simonepri</author>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_GangZoneCreate
		#undef FIX_GangZoneCreate
	#endif
	static stock FIX_GangZoneCreate = 0;
	#define FIX_GangZoneCreate                   (0)
#elseif !defined FIX_GangZoneCreate
	#define _FIXES_WARNING 42
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_GangZoneCreate = _FIXES_DEFAULT;
	#define FIX_GangZoneCreate                   _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_GangZoneCreate)
	#undef FIX_GangZoneCreate
	static stock FIX_GangZoneCreate = 2;
	#define FIX_GangZoneCreate                   (2)
#elseif FIX_GangZoneCreate
	#undef FIX_GangZoneCreate
	static stock FIX_GangZoneCreate = 1;
	#define FIX_GangZoneCreate                   (1)
#else
	#undef FIX_GangZoneCreate
	static stock FIX_GangZoneCreate = 0;
	#define FIX_GangZoneCreate                   (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="OnDialogResponse" fixed="0.3e RC6">
 *     <problem>
 *         Cheaters can spoof the dialogid they are using to respond to ones
 *         they can't actually see.
 *     </problem>
 *     <solution>
 *         Store the displayed dialogid and use that instead.
 *     </solution>
 *     <see>On_DialogResponse</see>
 *     <see>FIXES_ShowPlayerDialog</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_OnDialogResponse
		#undef FIX_OnDialogResponse
	#endif
	static stock FIX_OnDialogResponse = 0;
	#define FIX_OnDialogResponse                 (0)
#elseif !defined FIX_OnDialogResponse
	#if defined GetVehicleModelInfo
		#if FIXES_EnableDeprecated
			#define _FIXES_WARNING 43
			#tryinclude "_fixes_options"
			#undef _FIXES_WARNING
			static _FIXES_OPTION FIX_OnDialogResponse = FIXES_EnableDeprecated;
		#else
			_FIXES_CONST_PAWNDOC(FIX_OnDialogResponse = FIXES_EnableDeprecated);
		#endif
		#define FIX_OnDialogResponse             FIXES_EnableDeprecated
	#else
		#define _FIXES_WARNING 43
		#tryinclude "_fixes_options"
		#undef _FIXES_WARNING
		static _FIXES_OPTION FIX_OnDialogResponse = _FIXES_DEFAULT;
		#define FIX_OnDialogResponse             _FIXES_DEFAULT
	#endif
#elseif _FIXES_IS_UNSET(FIX_OnDialogResponse)
	#undef FIX_OnDialogResponse
	static stock FIX_OnDialogResponse = 2;
	#define FIX_OnDialogResponse                 (2)
#elseif FIX_OnDialogResponse
	#undef FIX_OnDialogResponse
	static stock FIX_OnDialogResponse = 1;
	#define FIX_OnDialogResponse                 (1)
#else
	#undef FIX_OnDialogResponse
	static stock FIX_OnDialogResponse = 0;
	#define FIX_OnDialogResponse                 (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="GetPlayerDialog" disabled="true">
 *     <problem>
 *         This function doesn't exist.  Fixed for hidden dialogs.
 *     </problem>
 *     <solution>
 *         Add it.
 *     </solution>
 *     <see>FIXES_GetPlayerDialog</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 *     <author    href="https://github.com/simonepri/" >simonepri</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_GetPlayerDialog
		#undef FIX_GetPlayerDialog
	#endif
	static stock FIX_GetPlayerDialog = 0;
	#define FIX_GetPlayerDialog                  (0)
#elseif !defined FIX_GetPlayerDialog
	#if defined GetPlayerDialog
		#if FIXES_EnableDeprecated
			#define _FIXES_WARNING 44
			#tryinclude "_fixes_options"
			#undef _FIXES_WARNING
			static _FIXES_OPTION FIX_GetPlayerDialog = FIXES_EnableDeprecated;
		#else
			_FIXES_CONST_PAWNDOC(FIX_GetPlayerDialog = FIXES_EnableDeprecated);
		#endif
		#define FIX_GetPlayerDialog              FIXES_EnableDeprecated
	#else
		#define _FIXES_WARNING 44
		#tryinclude "_fixes_options"
		#undef _FIXES_WARNING
		static _FIXES_OPTION FIX_GetPlayerDialog = FIX_API;
		#define FIX_GetPlayerDialog              FIX_API
	#endif
#elseif _FIXES_IS_UNSET(FIX_GetPlayerDialog)
	#undef FIX_GetPlayerDialog
	static stock FIX_GetPlayerDialog = 2;
	#define FIX_GetPlayerDialog                  (2)
#elseif FIX_GetPlayerDialog
	#undef FIX_GetPlayerDialog
	static stock FIX_GetPlayerDialog = 1;
	#define FIX_GetPlayerDialog                  (1)
#else
	#undef FIX_GetPlayerDialog
	static stock FIX_GetPlayerDialog = 0;
	#define FIX_GetPlayerDialog                  (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="PlayerDialogResponse">
 *     <problem>
 *         A player's dialog doesn't hide when the gamemode restarts, causing
 *         the server to print "Warning: PlayerDialogResponse PlayerId: 0
 *         dialog ID doesn't match last sent dialog ID".
 *     </problem>
 *     <solution>
 *         Hide it.
 *     </solution>
 *     <see>OnPlayerConnect</see>
 *     <see>OnGameModeExit</see>
 *     <author    href="https://github.com/simonepri/" >simonepri</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_PlayerDialogResponse
		#undef FIX_PlayerDialogResponse
	#endif
	static stock FIX_PlayerDialogResponse = 0;
	#define FIX_PlayerDialogResponse             (0)
#elseif !defined FIX_PlayerDialogResponse
	#define _FIXES_WARNING 45
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_PlayerDialogResponse = _FIXES_DEFAULT;
	#define FIX_PlayerDialogResponse             _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_PlayerDialogResponse)
	#undef FIX_PlayerDialogResponse
	static stock FIX_PlayerDialogResponse = 2;
	#define FIX_PlayerDialogResponse             (2)
#elseif FIX_PlayerDialogResponse
	#undef FIX_PlayerDialogResponse
	static stock FIX_PlayerDialogResponse = 1;
	#define FIX_PlayerDialogResponse             (1)
#else
	#undef FIX_PlayerDialogResponse
	static stock FIX_PlayerDialogResponse = 0;
	#define FIX_PlayerDialogResponse             (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="SetSpawnInfo">
 *     <problem>
 *         Kicks the player if "SpawnPlayer" is called before "SetSpawnInfo".
 *     </problem>
 *     <solution>
 *         Call "SetSpawnInfo" at least once.
 *     </solution>
 *     <see>OnPlayerConnect</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_SetSpawnInfo
		#undef FIX_SetSpawnInfo
	#endif
	static stock FIX_SetSpawnInfo = 0;
	#define FIX_SetSpawnInfo                     (0)
#elseif !defined FIX_SetSpawnInfo
	#if defined GetPlayerVersion
		#if FIXES_EnableDeprecated
			#define _FIXES_WARNING 46
			#tryinclude "_fixes_options"
			#undef _FIXES_WARNING
			static _FIXES_OPTION FIX_SetSpawnInfo = FIXES_EnableDeprecated;
		#else
			_FIXES_CONST_PAWNDOC(FIX_SetSpawnInfo = FIXES_EnableDeprecated);
		#endif
		#define FIX_SetSpawnInfo                 FIXES_EnableDeprecated
	#else
		#define _FIXES_WARNING 46
		#tryinclude "_fixes_options"
		#undef _FIXES_WARNING
		static _FIXES_OPTION FIX_SetSpawnInfo = _FIXES_DEFAULT;
		#define FIX_SetSpawnInfo                 _FIXES_DEFAULT
	#endif
#elseif _FIXES_IS_UNSET(FIX_SetSpawnInfo)
	#undef FIX_SetSpawnInfo
	static stock FIX_SetSpawnInfo = 2;
	#define FIX_SetSpawnInfo                     (2)
#elseif FIX_SetSpawnInfo
	#undef FIX_SetSpawnInfo
	static stock FIX_SetSpawnInfo = 1;
	#define FIX_SetSpawnInfo                     (1)
#else
	#undef FIX_SetSpawnInfo
	static stock FIX_SetSpawnInfo = 0;
	#define FIX_SetSpawnInfo                     (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="SetSpawnInfo_2">
 *     <problem>
 *         Does not set the correct team after spawn.
 *     </problem>
 *     <solution>
 *         Call "SetPlayerTeam" when they spawn.
 *     </solution>
 *     <see>OnPlayerSpawn</see>
 *     <author    href="https://sampforum.blast.hk/member.php?action=profile&amp;uid=24012" >NaS</author>
 *     <post      href="https://sampforum.blast.hk/showthread.php?tid=649396&amp;pid=3994248#pid3994248" />
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_SetSpawnInfo_2
		#undef FIX_SetSpawnInfo_2
	#endif
	static stock FIX_SetSpawnInfo_2 = 0;
	#define FIX_SetSpawnInfo_2                   (0)
#elseif !defined FIX_SetSpawnInfo_2
	#define _FIXES_WARNING 47
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_SetSpawnInfo_2 = _FIXES_DEFAULT;
	#define FIX_SetSpawnInfo_2                   _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_SetSpawnInfo_2)
	#undef FIX_SetSpawnInfo_2
	static stock FIX_SetSpawnInfo_2 = 2;
	#define FIX_SetSpawnInfo_2                   (2)
#elseif FIX_SetSpawnInfo_2
	#undef FIX_SetSpawnInfo_2
	static stock FIX_SetSpawnInfo_2 = 1;
	#define FIX_SetSpawnInfo_2                   (1)
#else
	#undef FIX_SetSpawnInfo_2
	static stock FIX_SetSpawnInfo_2 = 0;
	#define FIX_SetSpawnInfo_2                   (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="SetPlayerSkin">
 *     <problem>
 *         Breaks sitting on bikes.
 *     </problem>
 *     <solution>
 *         Put them back in the vehicle after setting their skin.
 *     </solution>
 *     <see>FIXES_SetPlayerSkin</see>
 *     <author    >CyNiC</author>
 *     <post      href="http://web-old.archive.org/web/20190415184621/https://forum.sa-mp.com/showpost.php?p=1756094" />
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_SetPlayerSkin
		#undef FIX_SetPlayerSkin
	#endif
	static stock FIX_SetPlayerSkin = 0;
	#define FIX_SetPlayerSkin                    (0)
#elseif !defined FIX_SetPlayerSkin
	#define _FIXES_WARNING 48
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_SetPlayerSkin = _FIXES_DEFAULT;
	#define FIX_SetPlayerSkin                    _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_SetPlayerSkin)
	#undef FIX_SetPlayerSkin
	static stock FIX_SetPlayerSkin = 2;
	#define FIX_SetPlayerSkin                    (2)
#elseif FIX_SetPlayerSkin
	#undef FIX_SetPlayerSkin
	static stock FIX_SetPlayerSkin = 1;
	#define FIX_SetPlayerSkin                    (1)
#else
	#undef FIX_SetPlayerSkin
	static stock FIX_SetPlayerSkin = 0;
	#define FIX_SetPlayerSkin                    (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="valstr">
 *     <problem>
 *         Crashes on large numbers.
 *     </problem>
 *     <solution>
 *         Use "format" instead.
 *     </solution>
 *     <see>FIXES_valstr</see>
 *     <author    href="https://github.com/oscar-broman/" >Slice</author>
 * </fix>
 */

#if !defined FIX_valstr
	#define _FIXES_WARNING 49
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_valstr = _FIXES_DEFAULT;
	#define FIX_valstr                           _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_valstr)
	#undef FIX_valstr
	static stock FIX_valstr = 2;
	#define FIX_valstr                           (2)
#elseif FIX_valstr
	#undef FIX_valstr
	static stock FIX_valstr = 1;
	#define FIX_valstr                           (1)
#else
	#undef FIX_valstr
	static stock FIX_valstr = 0;
	#define FIX_valstr                           (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="file_inc" disabled="true">
 *     <problem>
 *         Includes or excludes all the file function fixes together (can cause
 *         major overhead).
 *     </problem>
 *     <solution>
 *         Optionally group them all under one define.
 *     </solution>
 *     <see>FIX_file_inc</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 */

#if !defined FIX_file_inc
	#define _FIXES_WARNING 50
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_file_inc = _FIXES_DEFAULT;
	#define FIX_file_inc                         _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_file_inc)
	#undef FIX_file_inc
	static stock FIX_file_inc = 2;
	#define FIX_file_inc                         (2)
#elseif FIX_file_inc
	#undef FIX_file_inc
	static stock FIX_file_inc = 1;
	#define FIX_file_inc                         (1)
#else
	#undef FIX_file_inc
	static stock FIX_file_inc = 0;
	#define FIX_file_inc                         (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="fclose">
 *     <problem>
 *         Crashes on an invalid handle.
 *     </problem>
 *     <solution>
 *         Check for an invalid handle.
 *     </solution>
 *     <see>FIXES_fclose</see>
 *     <author    href="https://github.com/oscar-broman/" >Slice</author>
 * </fix>
 */

#if !defined FIX_fclose
	_FIXES_CONST_PAWNDOC(FIX_fclose = (FIX_file_inc));
	#define FIX_fclose                           (FIX_file_inc)
#elseif _FIXES_IS_UNSET(FIX_fclose)
	#undef FIX_fclose
	static stock FIX_fclose = 2;
	#define FIX_fclose                           (2)
#elseif FIX_fclose
	#undef FIX_fclose
	static stock FIX_fclose = 1;
	#define FIX_fclose                           (1)
#else
	#undef FIX_fclose
	static stock FIX_fclose = 0;
	#define FIX_fclose                           (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="fwrite">
 *     <problem>
 *         Crashes on an invalid handle.
 *     </problem>
 *     <solution>
 *         Check for an invalid handle.
 *     </solution>
 *     <see>FIXES_fwrite</see>
 *     <author    href="https://github.com/oscar-broman/" >Slice</author>
 * </fix>
 */

#if !defined FIX_fwrite
	_FIXES_CONST_PAWNDOC(FIX_fwrite = (FIX_file_inc));
	#define FIX_fwrite                           (FIX_file_inc)
#elseif _FIXES_IS_UNSET(FIX_fwrite)
	#undef FIX_fwrite
	static stock FIX_fwrite = 2;
	#define FIX_fwrite                           (2)
#elseif FIX_fwrite
	#undef FIX_fwrite
	static stock FIX_fwrite = 1;
	#define FIX_fwrite                           (1)
#else
	#undef FIX_fwrite
	static stock FIX_fwrite = 0;
	#define FIX_fwrite                           (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="fread">
 *     <problem>
 *         Crashes on an invalid handle.
 *     </problem>
 *     <solution>
 *         Check for an invalid handle.
 *     </solution>
 *     <see>FIXES_fread</see>
 *     <author    href="https://github.com/oscar-broman/" >Slice</author>
 * </fix>
 */

#if !defined FIX_fread
	_FIXES_CONST_PAWNDOC(FIX_fread = (FIX_file_inc));
	#define FIX_fread                            (FIX_file_inc)
#elseif _FIXES_IS_UNSET(FIX_fread)
	#undef FIX_fread
	static stock FIX_fread = 2;
	#define FIX_fread                            (2)
#elseif FIX_fread
	#undef FIX_fread
	static stock FIX_fread = 1;
	#define FIX_fread                            (1)
#else
	#undef FIX_fread
	static stock FIX_fread = 0;
	#define FIX_fread                            (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="fputchar">
 *     <problem>
 *         Crashes on an invalid handle.
 *     </problem>
 *     <solution>
 *         Check for an invalid handle.
 *     </solution>
 *     <see>FIXES_fputchar</see>
 *     <author    href="https://github.com/oscar-broman/" >Slice</author>
 * </fix>
 */

#if !defined FIX_fputchar
	_FIXES_CONST_PAWNDOC(FIX_fputchar = (FIX_file_inc));
	#define FIX_fputchar                         (FIX_file_inc)
#elseif _FIXES_IS_UNSET(FIX_fputchar)
	#undef FIX_fputchar
	static stock FIX_fputchar = 2;
	#define FIX_fputchar                         (2)
#elseif FIX_fputchar
	#undef FIX_fputchar
	static stock FIX_fputchar = 1;
	#define FIX_fputchar                         (1)
#else
	#undef FIX_fputchar
	static stock FIX_fputchar = 0;
	#define FIX_fputchar                         (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="fgetchar">
 *     <problem>
 *         Crashes on an invalid handle.
 *     </problem>
 *     <solution>
 *         Check for an invalid handle.
 *     </solution>
 *     <see>FIXES_fgetchar</see>
 *     <author    href="https://github.com/oscar-broman/" >Slice</author>
 * </fix>
 */

#if !defined FIX_fgetchar
	_FIXES_CONST_PAWNDOC(FIX_fgetchar = (FIX_file_inc));
	#define FIX_fgetchar                         (FIX_file_inc)
#elseif _FIXES_IS_UNSET(FIX_fgetchar)
	#undef FIX_fgetchar
	static stock FIX_fgetchar = 2;
	#define FIX_fgetchar                         (2)
#elseif FIX_fgetchar
	#undef FIX_fgetchar
	static stock FIX_fgetchar = 1;
	#define FIX_fgetchar                         (1)
#else
	#undef FIX_fgetchar
	static stock FIX_fgetchar = 0;
	#define FIX_fgetchar                         (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="fblockwrite">
 *     <problem>
 *         Crashes on an invalid handle.
 *     </problem>
 *     <solution>
 *         Check for an invalid handle.
 *     </solution>
 *     <see>FIXES_fblockwrite</see>
 *     <author    href="https://github.com/oscar-broman/" >Slice</author>
 * </fix>
 */

#if !defined FIX_fblockwrite
	_FIXES_CONST_PAWNDOC(FIX_fblockwrite = (FIX_file_inc));
	#define FIX_fblockwrite                      (FIX_file_inc)
#elseif _FIXES_IS_UNSET(FIX_fblockwrite)
	#undef FIX_fblockwrite
	static stock FIX_fblockwrite = 2;
	#define FIX_fblockwrite                      (2)
#elseif FIX_fblockwrite
	#undef FIX_fblockwrite
	static stock FIX_fblockwrite = 1;
	#define FIX_fblockwrite                      (1)
#else
	#undef FIX_fblockwrite
	static stock FIX_fblockwrite = 0;
	#define FIX_fblockwrite                      (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="fblockread">
 *     <problem>
 *         Crashes on an invalid handle.
 *     </problem>
 *     <solution>
 *         Check for an invalid handle.
 *     </solution>
 *     <see>FIXES_fblockread</see>
 *     <author    href="https://github.com/oscar-broman/" >Slice</author>
 * </fix>
 */

#if !defined FIX_fblockread
	_FIXES_CONST_PAWNDOC(FIX_fblockread = (FIX_file_inc));
	#define FIX_fblockread                       (FIX_file_inc)
#elseif _FIXES_IS_UNSET(FIX_fblockread)
	#undef FIX_fblockread
	static stock FIX_fblockread = 2;
	#define FIX_fblockread                       (2)
#elseif FIX_fblockread
	#undef FIX_fblockread
	static stock FIX_fblockread = 1;
	#define FIX_fblockread                       (1)
#else
	#undef FIX_fblockread
	static stock FIX_fblockread = 0;
	#define FIX_fblockread                       (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="fseek">
 *     <problem>
 *         Crashes on an invalid handle.
 *     </problem>
 *     <solution>
 *         Check for an invalid handle.
 *     </solution>
 *     <see>FIXES_fseek</see>
 *     <author    href="https://github.com/oscar-broman/" >Slice</author>
 * </fix>
 */

#if !defined FIX_fseek
	_FIXES_CONST_PAWNDOC(FIX_fseek = (FIX_file_inc));
	#define FIX_fseek                            (FIX_file_inc)
#elseif _FIXES_IS_UNSET(FIX_fseek)
	#undef FIX_fseek
	static stock FIX_fseek = 2;
	#define FIX_fseek                            (2)
#elseif FIX_fseek
	#undef FIX_fseek
	static stock FIX_fseek = 1;
	#define FIX_fseek                            (1)
#else
	#undef FIX_fseek
	static stock FIX_fseek = 0;
	#define FIX_fseek                            (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="flength">
 *     <problem>
 *         Crashes on an invalid handle.
 *     </problem>
 *     <solution>
 *         Check for an invalid handle.
 *     </solution>
 *     <see>FIXES_flength</see>
 *     <author    href="https://github.com/oscar-broman/" >Slice</author>
 * </fix>
 */

#if !defined FIX_flength
	_FIXES_CONST_PAWNDOC(FIX_flength = (FIX_file_inc));
	#define FIX_flength                          (FIX_file_inc)
#elseif _FIXES_IS_UNSET(FIX_flength)
	#undef FIX_flength
	static stock FIX_flength = 2;
	#define FIX_flength                          (2)
#elseif FIX_flength
	#undef FIX_flength
	static stock FIX_flength = 1;
	#define FIX_flength                          (1)
#else
	#undef FIX_flength
	static stock FIX_flength = 0;
	#define FIX_flength                          (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="SetPlayerAttachedObject">
 *     <problem>
 *         Doesn't remove objects when the mode ends.
 *     </problem>
 *     <solution>
 *         Remove them.
 *     </solution>
 *     <see>OnPlayerDisconnect</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_SetPlayerAttachedObject
		#undef FIX_SetPlayerAttachedObject
	#endif
	static stock FIX_SetPlayerAttachedObject = 0;
	#define FIX_SetPlayerAttachedObject          (0)
#elseif !defined FIX_SetPlayerAttachedObject
	#define _FIXES_WARNING 51
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_SetPlayerAttachedObject = _FIXES_DEFAULT;
	#define FIX_SetPlayerAttachedObject          _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_SetPlayerAttachedObject)
	#undef FIX_SetPlayerAttachedObject
	static stock FIX_SetPlayerAttachedObject = 2;
	#define FIX_SetPlayerAttachedObject          (2)
#elseif FIX_SetPlayerAttachedObject
	#undef FIX_SetPlayerAttachedObject
	static stock FIX_SetPlayerAttachedObject = 1;
	#define FIX_SetPlayerAttachedObject          (1)
#else
	#undef FIX_SetPlayerAttachedObject
	static stock FIX_SetPlayerAttachedObject = 0;
	#define FIX_SetPlayerAttachedObject          (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="OnPlayerDeath">
 *     <problem>
 *         Clients get stuck when they die with an animation applied.
 *     </problem>
 *     <solution>
 *         Clear their animations.
 *     </solution>
 *     <see>OnPlayerDeath</see>
 *     <see>OnPlayerUpdate</see>
 *     <author    >h02</author>
 *     <post      href="https://sampforum.blast.hk/showthread.php?tid=312862&amp;pid=1641144#pid1641144" />
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_OnPlayerDeath
		#undef FIX_OnPlayerDeath
	#endif
	static stock FIX_OnPlayerDeath = 0;
	#define FIX_OnPlayerDeath                    (0)
#elseif !defined FIX_OnPlayerDeath
	#define _FIXES_WARNING 52
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_OnPlayerDeath = _FIXES_DEFAULT;
	#define FIX_OnPlayerDeath                    _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_OnPlayerDeath)
	#undef FIX_OnPlayerDeath
	static stock FIX_OnPlayerDeath = 2;
	#define FIX_OnPlayerDeath                    (2)
#elseif FIX_OnPlayerDeath
	#undef FIX_OnPlayerDeath
	static stock FIX_OnPlayerDeath = 1;
	#define FIX_OnPlayerDeath                    (1)
#else
	#undef FIX_OnPlayerDeath
	static stock FIX_OnPlayerDeath = 0;
	#define FIX_OnPlayerDeath                    (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="strins">
 *     <problem>
 *         Ignores the "maxlength" parameter causing possible crashes.
 *     </problem>
 *     <solution>
 *         Manually check the length.
 *     </solution>
 *     <see>FIXES_strins</see>
 *     <author    href="https://github.com/oscar-broman/" >Slice</author>
 *     <author    href="https://github.com/Y-Less" >Y_Less</author>
 * </fix>
 */

#if !defined FIX_strins
	#define _FIXES_WARNING 53
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_strins = _FIXES_DEFAULT;
	#define FIX_strins                           _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_strins)
	#undef FIX_strins
	static stock FIX_strins = 2;
	#define FIX_strins                           (2)
#elseif FIX_strins
	#undef FIX_strins
	static stock FIX_strins = 1;
	#define FIX_strins                           (1)
#else
	#undef FIX_strins
	static stock FIX_strins = 0;
	#define FIX_strins                           (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="IsPlayerConnected">
 *     <problem>
 *         Only uses the lower two bytes of a passed ID.
 *     </problem>
 *     <solution>
 *         Mask the numbers.
 *     </solution>
 *     <see>FIXES_IsPlayerConnected</see>
 *     <author    href="https://github.com/oscar-broman/" >Slice</author>
 * </fix>
 */

#if !defined FIX_IsPlayerConnected
	#define _FIXES_WARNING 54
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_IsPlayerConnected = _FIXES_DEFAULT;
	#define FIX_IsPlayerConnected                _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_IsPlayerConnected)
	#undef FIX_IsPlayerConnected
	static stock FIX_IsPlayerConnected = 2;
	#define FIX_IsPlayerConnected                (2)
#elseif FIX_IsPlayerConnected
	#undef FIX_IsPlayerConnected
	static stock FIX_IsPlayerConnected = 1;
	#define FIX_IsPlayerConnected                (1)
#else
	#undef FIX_IsPlayerConnected
	static stock FIX_IsPlayerConnected = 0;
	#define FIX_IsPlayerConnected                (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="TrainExit">
 *     <problem>
 *         When getting out of a train entered by "PutPlayerInVehicle", the
 *         camera does not reset properly.
 *     </problem>
 *     <solution>
 *         Reset the camera.
 *     </solution>
 *     <see>FIXES_PutPlayerInVehicle</see>
 *     <see>On_PlayerStateChange</see>
 *     <author    >Terminator3</author>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_TrainExit
		#undef FIX_TrainExit
	#endif
	static stock FIX_TrainExit = 0;
	#define FIX_TrainExit                        (0)
#elseif !defined FIX_TrainExit
	#define _FIXES_WARNING 55
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_TrainExit = _FIXES_DEFAULT;
	#define FIX_TrainExit                        _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_TrainExit)
	#undef FIX_TrainExit
	static stock FIX_TrainExit = 2;
	#define FIX_TrainExit                        (2)
#elseif FIX_TrainExit
	#undef FIX_TrainExit
	static stock FIX_TrainExit = 1;
	#define FIX_TrainExit                        (1)
#else
	#undef FIX_TrainExit
	static stock FIX_TrainExit = 0;
	#define FIX_TrainExit                        (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="Kick" fixed="0.3x">
 *     <problem>
 *         Calling "Kick" in "OnPlayerConnect" doesn't work properly.
 *     </problem>
 *     <solution>
 *         Defer it.
 *     </solution>
 *     <see>OnPlayerConnect</see>
 *     <see>FIXES_Kick</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 *     <post      href="http://web-old.archive.org/web/20170819203349/http://forum.sa-mp.com/showpost.php?p=1989453" />
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_Kick
		#undef FIX_Kick
	#endif
	static stock FIX_Kick = 0;
	#define FIX_Kick                          (0)
#elseif !defined FIX_Kick
	#if defined EnableVehicleFriendlyFire
		#if FIXES_EnableDeprecated
			#define _FIXES_WARNING 56
			#tryinclude "_fixes_options"
			#undef _FIXES_WARNING
			static _FIXES_OPTION FIX_Kick = FIXES_EnableDeprecated;
		#else
			_FIXES_CONST_PAWNDOC(FIX_Kick = FIXES_EnableDeprecated);
		#endif
		#define FIX_Kick                         FIXES_EnableDeprecated
	#else
		#define _FIXES_WARNING 56
		#tryinclude "_fixes_options"
		#undef _FIXES_WARNING
		static _FIXES_OPTION FIX_Kick = _FIXES_DEFAULT;
		#define FIX_Kick                         _FIXES_DEFAULT
	#endif
#elseif _FIXES_IS_UNSET(FIX_Kick)
	#undef FIX_Kick
	static stock FIX_Kick = 2;
	#define FIX_Kick                             (2)
#elseif FIX_Kick
	#undef FIX_Kick
	static stock FIX_Kick = 1;
	#define FIX_Kick                             (1)
#else
	#undef FIX_Kick
	static stock FIX_Kick = 0;
	#define FIX_Kick                             (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="OnVehicleMod">
 *     <problem>
 *         Crashes other players when invalid mods are applied.
 *     </problem>
 *     <solution>
 *         Desync the player.
 *     </solution>
 *     <see>OnVehicleMod</see>
 *     <author    href="https://github.com/JernejL/" >JernejL</author>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 *     <post      href="https://sampforum.blast.hk/showthread.php?tid=317303&amp;pid=1671500#pid1671500" />
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_OnVehicleMod
		#undef FIX_OnVehicleMod
	#endif
	static stock FIX_OnVehicleMod = 0;
	#define FIX_OnVehicleMod                     (0)
#elseif !defined FIX_OnVehicleMod
	#define _FIXES_WARNING 57
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_OnVehicleMod = _FIXES_DEFAULT;
	#define FIX_OnVehicleMod                     _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_OnVehicleMod)
	#undef FIX_OnVehicleMod
	static stock FIX_OnVehicleMod = 2;
	#define FIX_OnVehicleMod                     (2)
#elseif FIX_OnVehicleMod
	#undef FIX_OnVehicleMod
	static stock FIX_OnVehicleMod = 1;
	#define FIX_OnVehicleMod                     (1)
#else
	#undef FIX_OnVehicleMod
	static stock FIX_OnVehicleMod = 0;
	#define FIX_OnVehicleMod                     (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="random" disabled="true">
 *     <problem>
 *         Doesn't work with negative numbers.
 *     </problem>
 *     <solution>
 *         Invert then reinvert.
 *     </solution>
 *     <see>FIXES_random</see>
 *     <author    href="https://github.com/simonepri/" >simonepri</author>
 * </fix>
 */

#if !defined FIX_random
	#define _FIXES_WARNING 58
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_random = _FIXES_DEFAULT;
	#define FIX_random                           _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_random)
	#undef FIX_random
	static stock FIX_random = 2;
	#define FIX_random                           (2)
#elseif FIX_random
	#undef FIX_random
	static stock FIX_random = 1;
	#define FIX_random                           (1)
#else
	#undef FIX_random
	static stock FIX_random = 0;
	#define FIX_random                           (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="sleep">
 *     <problem>
 *         Leaks bytes from the stack.
 *     </problem>
 *     <solution>
 *         Call a function to store the correct value.
 *     </solution>
 *     <see>FIXES_sleep</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 */

#if !defined FIX_sleep
	#define _FIXES_WARNING 59
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_sleep = _FIXES_DEFAULT;
	#define FIX_sleep                            _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_sleep)
	#undef FIX_sleep
	static stock FIX_sleep = 2;
	#define FIX_sleep                            (2)
#elseif FIX_sleep
	#undef FIX_sleep
	static stock FIX_sleep = 1;
	#define FIX_sleep                            (1)
#else
	#undef FIX_sleep
	static stock FIX_sleep = 0;
	#define FIX_sleep                            (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="Menus">
 *     <problem>
 *         All menu function fixes are included separately for major overhead.
 *     </problem>
 *     <solution>
 *         Optionally group them all under one define.
 *     </solution>
 *     <see>FIX_Menus</see>
 *     <see>_FIX_Menus</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_Menus
		#undef FIX_Menus
	#endif
	static stock FIX_Menus = 0;
	#define FIX_Menus                            (0)
#elseif !defined FIX_Menus
	#define _FIXES_WARNING 60
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_Menus = _FIXES_DEFAULT;
	#define FIX_Menus                            _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_Menus)
	#undef FIX_Menus
	static stock FIX_Menus = 2;
	#define FIX_Menus                            (2)
#elseif FIX_Menus
	#undef FIX_Menus
	static stock FIX_Menus = 1;
	#define FIX_Menus                            (1)
#else
	#undef FIX_Menus
	static stock FIX_Menus = 0;
	#define FIX_Menus                            (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="AddMenuItem">
 *     <problem>
 *         Crashes when passed an invalid menu ID.
 *     </problem>
 *     <solution>
 *         Don't hide it when passed an invalid menu.
 *     </solution>
 *     <see>FIXES_AddMenuItem</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_AddMenuItem
		#undef FIX_AddMenuItem
	#endif
	static stock FIX_AddMenuItem = 0;
	#define FIX_AddMenuItem                      (0)
#elseif !defined FIX_AddMenuItem
	#define _FIXES_WARNING 61
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_AddMenuItem = FIX_Menus;
	#define FIX_AddMenuItem                      FIX_Menus
#elseif _FIXES_IS_UNSET(FIX_AddMenuItem)
	#undef FIX_AddMenuItem
	static stock FIX_AddMenuItem = 2;
	#define FIX_AddMenuItem                      (2)
#elseif FIX_AddMenuItem
	#undef FIX_AddMenuItem
	static stock FIX_AddMenuItem = 1;
	#define FIX_AddMenuItem                      (1)
#else
	#undef FIX_AddMenuItem
	static stock FIX_AddMenuItem = 0;
	#define FIX_AddMenuItem                      (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="SetMenuColumnHeader">
 *     <problem>
 *         Crashes when passed an invalid menu ID.
 *     </problem>
 *     <solution>
 *         Don't hide it when passed an invalid menu.
 *     </solution>
 *     <see>FIXES_SetMenuColumnHeader</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_SetMenuColumnHeader
		#undef FIX_SetMenuColumnHeader
	#endif
	static stock FIX_SetMenuColumnHeader = 0;
	#define FIX_SetMenuColumnHeader              (0)
#elseif !defined FIX_SetMenuColumnHeader
	#define _FIXES_WARNING 62
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_SetMenuColumnHeader = FIX_Menus;
	#define FIX_SetMenuColumnHeader              FIX_Menus
#elseif _FIXES_IS_UNSET(FIX_SetMenuColumnHeader)
	#undef FIX_SetMenuColumnHeader
	static stock FIX_SetMenuColumnHeader = 2;
	#define FIX_SetMenuColumnHeader              (2)
#elseif FIX_SetMenuColumnHeader
	#undef FIX_SetMenuColumnHeader
	static stock FIX_SetMenuColumnHeader = 1;
	#define FIX_SetMenuColumnHeader              (1)
#else
	#undef FIX_SetMenuColumnHeader
	static stock FIX_SetMenuColumnHeader = 0;
	#define FIX_SetMenuColumnHeader              (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="ShowMenuForPlayer">
 *     <problem>
 *         Crashes when passed an invalid menu ID.
 *     </problem>
 *     <solution>
 *         Don't hide it when passed an invalid menu.
 *     </solution>
 *     <see>FIXES_ShowMenuForPlayer</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_ShowMenuForPlayer
		#undef FIX_ShowMenuForPlayer
	#endif
	static stock FIX_ShowMenuForPlayer = 0;
	#define FIX_ShowMenuForPlayer                (0)
#elseif !defined FIX_ShowMenuForPlayer
	#define _FIXES_WARNING 63
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_ShowMenuForPlayer = FIX_Menus;
	#define FIX_ShowMenuForPlayer                FIX_Menus
#elseif _FIXES_IS_UNSET(FIX_ShowMenuForPlayer)
	#undef FIX_ShowMenuForPlayer
	static stock FIX_ShowMenuForPlayer = 2;
	#define FIX_ShowMenuForPlayer                (2)
#elseif FIX_ShowMenuForPlayer
	#undef FIX_ShowMenuForPlayer
	static stock FIX_ShowMenuForPlayer = 1;
	#define FIX_ShowMenuForPlayer                (1)
#else
	#undef FIX_ShowMenuForPlayer
	static stock FIX_ShowMenuForPlayer = 0;
	#define FIX_ShowMenuForPlayer                (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="HideMenuForPlayer">
 *     <problem>
 *         Crashes when passed an invalid menu ID.
 *     </problem>
 *     <solution>
 *         Don't hide it when passed an invalid menu.
 *     </solution>
 *     <see>FIXES_HideMenuForPlayer</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 *     <post      href="https://sampforum.blast.hk/showthread.php?tid=332944&amp;pid=1787297#pid1787297" />
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_HideMenuForPlayer
		#undef FIX_HideMenuForPlayer
	#endif
	static stock FIX_HideMenuForPlayer = 0;
	#define FIX_HideMenuForPlayer                (0)
#elseif !defined FIX_HideMenuForPlayer
	#define _FIXES_WARNING 64
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_HideMenuForPlayer = FIX_Menus;
	#define FIX_HideMenuForPlayer                FIX_Menus
#elseif _FIXES_IS_UNSET(FIX_HideMenuForPlayer)
	#undef FIX_HideMenuForPlayer
	static stock FIX_HideMenuForPlayer = 2;
	#define FIX_HideMenuForPlayer                (2)
#elseif FIX_HideMenuForPlayer
	#undef FIX_HideMenuForPlayer
	static stock FIX_HideMenuForPlayer = 1;
	#define FIX_HideMenuForPlayer                (1)
#else
	#undef FIX_HideMenuForPlayer
	static stock FIX_HideMenuForPlayer = 0;
	#define FIX_HideMenuForPlayer                (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="GetPlayerMenu">
 *     <problem>
 *         Returns previous menu when none is displayed.
 *     </problem>
 *     <solution>
 *         Return the correct value.
 *     </solution>
 *     <see>FIXES_GetPlayerMenu</see>
 *     <see>OnPlayerSelectedMenuRow</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_GetPlayerMenu
		#undef FIX_GetPlayerMenu
	#endif
	static stock FIX_GetPlayerMenu = 0;
	#define FIX_GetPlayerMenu                    (0)
#elseif !defined FIX_GetPlayerMenu
	#define _FIXES_WARNING 65
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_GetPlayerMenu = _FIXES_DEFAULT;
	#define FIX_GetPlayerMenu                    _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_GetPlayerMenu)
	#undef FIX_GetPlayerMenu
	static stock FIX_GetPlayerMenu = 2;
	#define FIX_GetPlayerMenu                    (2)
#elseif FIX_GetPlayerMenu
	#undef FIX_GetPlayerMenu
	static stock FIX_GetPlayerMenu = 1;
	#define FIX_GetPlayerMenu                    (1)
#else
	#undef FIX_GetPlayerMenu
	static stock FIX_GetPlayerMenu = 0;
	#define FIX_GetPlayerMenu                    (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="HideMenuForPlayer_2" disabled="true">
 *     <problem>
 *         Ignores the "menuid" parameter.
 *     </problem>
 *     <solution>
 *         Only hide the correct menu.
 *     </solution>
 *     <see>FIXES_HideMenuForPlayer</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_HideMenuForPlayer_2
		#undef FIX_HideMenuForPlayer_2
	#endif
	static stock FIX_HideMenuForPlayer_2 = 0;
	#define FIX_HideMenuForPlayer_2              (0)
#elseif !defined FIX_HideMenuForPlayer_2
	#define _FIXES_WARNING 66
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_HideMenuForPlayer_2 = FIXES_EnableAll;
	#define FIX_HideMenuForPlayer_2              FIXES_EnableAll
#elseif _FIXES_IS_UNSET(FIX_HideMenuForPlayer_2)
	#undef FIX_HideMenuForPlayer_2
	static stock FIX_HideMenuForPlayer_2 = 2;
	#define FIX_HideMenuForPlayer_2              (2)
#elseif FIX_HideMenuForPlayer_2 && !FIX_GetPlayerMenu
	#error FIX_HideMenuForPlayer_2 requires FIX_GetPlayerMenu
#elseif FIX_HideMenuForPlayer_2
	#undef FIX_HideMenuForPlayer_2
	static stock FIX_HideMenuForPlayer_2 = 1;
	#define FIX_HideMenuForPlayer_2              (1)
#else
	#undef FIX_HideMenuForPlayer_2
	static stock FIX_HideMenuForPlayer_2 = 0;
	#define FIX_HideMenuForPlayer_2              (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="DisableMenu">
 *     <problem>
 *         Crashes when passed an invalid menu ID.
 *     </problem>
 *     <solution>
 *         Don't hide it when passed an invalid menu.
 *     </solution>
 *     <see>FIXES_DisableMenu</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_DisableMenu
		#undef FIX_DisableMenu
	#endif
	static stock FIX_DisableMenu = 0;
	#define FIX_DisableMenu                      (0)
#elseif !defined FIX_DisableMenu
	#define _FIXES_WARNING 67
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_DisableMenu = FIX_Menus;
	#define FIX_DisableMenu                      FIX_Menus
#elseif _FIXES_IS_UNSET(FIX_DisableMenu)
	#undef FIX_DisableMenu
	static stock FIX_DisableMenu = 2;
	#define FIX_DisableMenu                      (2)
#elseif FIX_DisableMenu
	#undef FIX_DisableMenu
	static stock FIX_DisableMenu = 1;
	#define FIX_DisableMenu                      (1)
#else
	#undef FIX_DisableMenu
	static stock FIX_DisableMenu = 0;
	#define FIX_DisableMenu                      (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="DisableMenuRow">
 *     <problem>
 *         Crashes when passed an invalid menu ID.
 *     </problem>
 *     <solution>
 *         Don't hide it when passed an invalid menu.
 *     </solution>
 *     <see>FIXES_DisableMenuRow</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_DisableMenuRow
		#undef FIX_DisableMenuRow
	#endif
	static stock FIX_DisableMenuRow = 0;
	#define FIX_DisableMenuRow                   (0)
#elseif !defined FIX_DisableMenuRow
	#define _FIXES_WARNING 68
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_DisableMenuRow = FIX_Menus;
	#define FIX_DisableMenuRow                   FIX_Menus
#elseif _FIXES_IS_UNSET(FIX_DisableMenuRow)
	#undef FIX_DisableMenuRow
	static stock FIX_DisableMenuRow = 2;
	#define FIX_DisableMenuRow                   (2)
#elseif FIX_DisableMenuRow
	#undef FIX_DisableMenuRow
	static stock FIX_DisableMenuRow = 1;
	#define FIX_DisableMenuRow                   (1)
#else
	#undef FIX_DisableMenuRow
	static stock FIX_DisableMenuRow = 0;
	#define FIX_DisableMenuRow                   (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="GetPlayerInterior">
 *     <problem>
 *         Always returns 0 for NPCs.
 *     </problem>
 *     <solution>
 *         Return the correct value.
 *     </solution>
 *     <see>FIXES_GetPlayerInterior</see>
 *     <see>FIXES_SetPlayerInterior</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 *     <author    href="https://github.com/simonepri/" >simonepri</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_GetPlayerInterior
		#undef FIX_GetPlayerInterior
	#endif
	static stock FIX_GetPlayerInterior = 0;
	#define FIX_GetPlayerInterior                (0)
#elseif !defined FIX_GetPlayerInterior
	#define _FIXES_WARNING 69
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_GetPlayerInterior = _FIXES_DEFAULT;
	#define FIX_GetPlayerInterior                _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_GetPlayerInterior)
	#undef FIX_GetPlayerInterior
	static stock FIX_GetPlayerInterior = 2;
	#define FIX_GetPlayerInterior                (2)
#elseif FIX_GetPlayerInterior
	#undef FIX_GetPlayerInterior
	static stock FIX_GetPlayerInterior = 1;
	#define FIX_GetPlayerInterior                (1)
#else
	#undef FIX_GetPlayerInterior
	static stock FIX_GetPlayerInterior = 0;
	#define FIX_GetPlayerInterior                (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="ApplyAnimation">
 *     <problem>
 *         Passing an invalid animation library in ApplyAnimation causes a
 *         client crash for streamed in players.
 *     </problem>
 *     <solution>
 *         Block ApplyAnimation when an invalid library is passed.
 *     </solution>
 *     <see>FIXES_ApplyAnimation</see>
 *     <author    href="https://github.com/simonepri/" >simonepri</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_ApplyAnimation
		#undef FIX_ApplyAnimation
	#endif
	static stock FIX_ApplyAnimation = 0;
	#define FIX_ApplyAnimation                   (0)
#elseif !defined FIX_ApplyAnimation
	#define _FIXES_WARNING 70
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_ApplyAnimation = _FIXES_DEFAULT;
	#define FIX_ApplyAnimation                   _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_ApplyAnimation)
	#undef FIX_ApplyAnimation
	static stock FIX_ApplyAnimation = 2;
	#define FIX_ApplyAnimation                   (2)
#elseif FIX_ApplyAnimation
	#undef FIX_ApplyAnimation
	static stock FIX_ApplyAnimation = 1;
	#define FIX_ApplyAnimation                   (1)
#else
	#undef FIX_ApplyAnimation
	static stock FIX_ApplyAnimation = 0;
	#define FIX_ApplyAnimation                   (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="ApplyAnimation_2">
 *     <problem>
 *         First time a library is used, it does nothing.
 *     </problem>
 *     <solution>
 *         Apply animations twice when first using a library.
 *     </solution>
 *     <see>FIXES_ApplyAnimation</see>
 *     <author    href="https://github.com/simonepri/" >simonepri</author>
 *     <author    href="https://github.com/Lordzy/" >Lordzy</author>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_ApplyAnimation_2
		#undef FIX_ApplyAnimation_2
	#endif
	static stock FIX_ApplyAnimation_2 = 0;
	#define FIX_ApplyAnimation_2                 (0)
#elseif !defined FIX_ApplyAnimation_2
	#define _FIXES_WARNING 71
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_ApplyAnimation_2 = _FIXES_DEFAULT;
	#define FIX_ApplyAnimation_2                 _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_ApplyAnimation_2)
	#undef FIX_ApplyAnimation_2
	static stock FIX_ApplyAnimation_2 = 2;
	#define FIX_ApplyAnimation_2                 (2)
#elseif FIX_ApplyAnimation_2
	#undef FIX_ApplyAnimation_2
	static stock FIX_ApplyAnimation_2 = 1;
	#define FIX_ApplyAnimation_2                 (1)
#else
	#undef FIX_ApplyAnimation_2
	static stock FIX_ApplyAnimation_2 = 0;
	#define FIX_ApplyAnimation_2                 (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="ApplyActorAnimation">
 *     <problem>
 *         Passing an invalid animation library in ApplyAnimation causes a
 *         client crash for streamed in players.
 *     </problem>
 *     <solution>
 *         Block ApplyActorAnimation when an invalid library is passed.
 *     </solution>
 *     <see>FIXES_ApplyActorAnimation</see>
 *     <author    href="https://github.com/simonepri/" >simonepri</author>
 *     <author    href="https://github.com/ziggi/" >ziggi</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_ApplyActorAnimation
		#undef FIX_ApplyActorAnimation
	#endif
	static stock FIX_ApplyActorAnimation = 0;
	#define FIX_ApplyActorAnimation              (0)
#elseif !defined FIX_ApplyActorAnimation
	#define _FIXES_WARNING 72
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_ApplyActorAnimation = _FIXES_DEFAULT;
	#define FIX_ApplyActorAnimation              _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_ApplyActorAnimation)
	#undef FIX_ApplyActorAnimation
	static stock FIX_ApplyActorAnimation = 2;
	#define FIX_ApplyActorAnimation              (2)
#elseif FIX_ApplyActorAnimation
	#undef FIX_ApplyActorAnimation
	static stock FIX_ApplyActorAnimation = 1;
	#define FIX_ApplyActorAnimation              (1)
#else
	#undef FIX_ApplyActorAnimation
	static stock FIX_ApplyActorAnimation = 0;
	#define FIX_ApplyActorAnimation              (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="ApplyActorAnimation_2">
 *     <problem>
 *         First time a library is used, it does nothing.
 *     </problem>
 *     <solution>
 *         Apply animations twice when first using a library.
 *     </solution>
 *     <see>FIXES_ApplyActorAnimation</see>
 *     <author    href="https://github.com/simonepri/" >simonepri</author>
 *     <author    href="https://github.com/Lordzy/" >Lordzy</author>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 *     <author    href="https://github.com/ziggi/" >ziggi</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_ApplyActorAnimation_2
		#undef FIX_ApplyActorAnimation_2
	#endif
	static stock FIX_ApplyActorAnimation_2 = 0;
	#define FIX_ApplyActorAnimation_2            (0)
#elseif !defined FIX_ApplyActorAnimation_2
	#define _FIXES_WARNING 73
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_ApplyActorAnimation_2 = _FIXES_DEFAULT;
	#define FIX_ApplyActorAnimation_2            _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_ApplyActorAnimation_2)
	#undef FIX_ApplyActorAnimation_2
	static stock FIX_ApplyActorAnimation_2 = 2;
	#define FIX_ApplyActorAnimation_2            (2)
#elseif FIX_ApplyActorAnimation_2
	#undef FIX_ApplyActorAnimation_2
	static stock FIX_ApplyActorAnimation_2 = 1;
	#define FIX_ApplyActorAnimation_2            (1)
#else
	#undef FIX_ApplyActorAnimation_2
	static stock FIX_ApplyActorAnimation_2 = 0;
	#define FIX_ApplyActorAnimation_2            (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="OnPlayerSpawn">
 *     <problem>
 *         San Andreas deducts $100 from players.
 *     </problem>
 *     <solution>
 *         Reset the player's money to what it was before they died.
 *     </solution>
 *     <see>OnPlayerSpawn</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_OnPlayerSpawn
		#undef FIX_OnPlayerSpawn
	#endif
	static stock FIX_OnPlayerSpawn = 0;
	#define FIX_OnPlayerSpawn                    (0)
#elseif !defined FIX_OnPlayerSpawn
	#define _FIXES_WARNING 74
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_OnPlayerSpawn = _FIXES_DEFAULT;
	#define FIX_OnPlayerSpawn                    _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_OnPlayerSpawn)
	#undef FIX_OnPlayerSpawn
	static stock FIX_OnPlayerSpawn = 2;
	#define FIX_OnPlayerSpawn                    (2)
#elseif FIX_OnPlayerSpawn
	#undef FIX_OnPlayerSpawn
	static stock FIX_OnPlayerSpawn = 1;
	#define FIX_OnPlayerSpawn                    (1)
#else
	#undef FIX_OnPlayerSpawn
	static stock FIX_OnPlayerSpawn = 0;
	#define FIX_OnPlayerSpawn                    (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="GameText">
 *     <problem>
 *         Several styles do not display for the time specified.
 *     </problem>
 *     <solution>
 *         Recreate the styles in Text Draws and use those instead.
 *     </solution>
 *     <see>FIXES_GameTextForAll</see>
 *     <see>FIXES_GameTextForPlayer</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_GameText
		#undef FIX_GameText
	#endif
	static stock FIX_GameText = 0;
	#define FIX_GameText                         (0)
#elseif !defined FIX_GameText
	#define _FIXES_WARNING 75
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_GameText = _FIXES_DEFAULT;
	#define FIX_GameText                         _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_GameText)
	#undef FIX_GameText
	static stock FIX_GameText = 2;
	#define FIX_GameText                         (2)
#elseif FIX_GameText
	#undef FIX_GameText
	static stock FIX_GameText = 1;
	#define FIX_GameText                         (1)
#else
	#undef FIX_GameText
	static stock FIX_GameText = 0;
	#define FIX_GameText                         (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="HideGameText">
 *     <problem>
 *         There is no "HideGameTextForXYZ" function.
 *     </problem>
 *     <solution>
 *         Show a single space for a game text.
 *     </solution>
 *     <see>FIXES_HideGameTextForAll</see>
 *     <see>FIXES_HideGameTextForPlayer</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_HideGameText
		#undef FIX_HideGameText
	#endif
	static stock FIX_HideGameText = 0;
	#define FIX_HideGameText                     (0)
#elseif !defined FIX_HideGameText
	#if defined HideGameText
		#if FIXES_EnableDeprecated
			#define _FIXES_WARNING 76
			#tryinclude "_fixes_options"
			#undef _FIXES_WARNING
			static _FIXES_OPTION FIX_HideGameText = FIXES_EnableDeprecated;
		#else
			_FIXES_CONST_PAWNDOC(FIX_HideGameText = FIXES_EnableDeprecated);
		#endif
		#define FIX_HideGameText                 FIXES_EnableDeprecated
	#else
		#define _FIXES_WARNING 76
		#tryinclude "_fixes_options"
		#undef _FIXES_WARNING
		static _FIXES_OPTION FIX_HideGameText = FIX_API;
		#define FIX_HideGameText                 FIX_API
	#endif
#elseif _FIXES_IS_UNSET(FIX_HideGameText)
	#undef FIX_HideGameText
	static stock FIX_HideGameText = 2;
	#define FIX_HideGameText                     (2)
#elseif FIX_HideGameText
	#undef FIX_HideGameText
	static stock FIX_HideGameText = 1;
	#define FIX_HideGameText                     (1)
#else
	#undef FIX_HideGameText
	static stock FIX_HideGameText = 0;
	#define FIX_HideGameText                     (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="GetPlayerWorldBounds">
 *     <problem>
 *         There is no "GetPlayerWorldBounds" function.
 *     </problem>
 *     <solution>
 *         Store them and retrieve them.
 *     </solution>
 *     <see>FIXES_GetPlayerWorldBounds</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_GetPlayerWorldBounds
		#undef FIX_GetPlayerWorldBounds
	#endif
	static stock FIX_GetPlayerWorldBounds = 0;
	#define FIX_GetPlayerWorldBounds             (0)
#elseif !defined FIX_GetPlayerWorldBounds
	#if defined GetPlayerWorldBounds
		#if FIXES_EnableDeprecated
			#define _FIXES_WARNING 77
			#tryinclude "_fixes_options"
			#undef _FIXES_WARNING
			static _FIXES_OPTION FIX_GetPlayerWorldBounds = FIXES_EnableDeprecated;
		#else
			_FIXES_CONST_PAWNDOC(FIX_GetPlayerWorldBounds = FIXES_EnableDeprecated);
		#endif
		#define FIX_GetPlayerWorldBounds         FIXES_EnableDeprecated
	#else
		#define _FIXES_WARNING 77
		#tryinclude "_fixes_options"
		#undef _FIXES_WARNING
		static _FIXES_OPTION FIX_GetPlayerWorldBounds = FIX_API;
		#define FIX_GetPlayerWorldBounds         FIX_API
	#endif
#elseif _FIXES_IS_UNSET(FIX_GetPlayerWorldBounds)
	#undef FIX_GetPlayerWorldBounds
	static stock FIX_GetPlayerWorldBounds = 2;
	#define FIX_GetPlayerWorldBounds             (2)
#elseif FIX_GetPlayerWorldBounds
	#undef FIX_GetPlayerWorldBounds
	static stock FIX_GetPlayerWorldBounds = 1;
	#define FIX_GetPlayerWorldBounds             (1)
#else
	#undef FIX_GetPlayerWorldBounds
	static stock FIX_GetPlayerWorldBounds = 0;
	#define FIX_GetPlayerWorldBounds             (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="ClearPlayerWorldBounds">
 *     <problem>
 *         There is no "ClearPlayerWorldBounds" function.
 *     </problem>
 *     <solution>
 *         Put the world bounds back to the default.
 *     </solution>
 *     <see>FIXES_ClearPlayerWorldBounds</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_ClearPlayerWorldBounds
		#undef FIX_ClearPlayerWorldBounds
	#endif
	static stock FIX_ClearPlayerWorldBounds = 0;
	#define FIX_ClearPlayerWorldBounds           (0)
#elseif !defined FIX_ClearPlayerWorldBounds
	#if defined ClearPlayerWorldBounds
		#if FIXES_EnableDeprecated
			#define _FIXES_WARNING 78
			#tryinclude "_fixes_options"
			#undef _FIXES_WARNING
			static _FIXES_OPTION FIX_ClearPlayerWorldBounds = FIXES_EnableDeprecated;
		#else
			_FIXES_CONST_PAWNDOC(FIX_ClearPlayerWorldBounds = FIXES_EnableDeprecated);
		#endif
		#define FIX_ClearPlayerWorldBounds       FIXES_EnableDeprecated
	#else
		#define _FIXES_WARNING 78
		#tryinclude "_fixes_options"
		#undef _FIXES_WARNING
		static _FIXES_OPTION FIX_ClearPlayerWorldBounds = FIX_API;
		#define FIX_ClearPlayerWorldBounds       FIX_API
	#endif
#elseif _FIXES_IS_UNSET(FIX_ClearPlayerWorldBounds)
	#undef FIX_ClearPlayerWorldBounds
	static stock FIX_ClearPlayerWorldBounds = 2;
	#define FIX_ClearPlayerWorldBounds           (2)
#elseif FIX_ClearPlayerWorldBounds
	#undef FIX_ClearPlayerWorldBounds
	static stock FIX_ClearPlayerWorldBounds = 1;
	#define FIX_ClearPlayerWorldBounds           (1)
#else
	#undef FIX_ClearPlayerWorldBounds
	static stock FIX_ClearPlayerWorldBounds = 0;
	#define FIX_ClearPlayerWorldBounds           (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="GameTextStyles" disabled="true">
 *     <problem>
 *         San Andreas has fixed styles for area and vehicle names, but they are
 *         not included in the GameText styles list.
 *     </problem>
 *     <solution>
 *         Add them.
 *     </solution>
 *     <see>FIXES_GameTextForAll</see>
 *     <see>FIXES_GameTextForPlayer</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 *     <author    href="https://github.com/NexiusTailer">NexiusTailer</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_GameTextStyles
		#undef FIX_GameTextStyles
	#endif
	static stock FIX_GameTextStyles = 0;
	#define FIX_GameTextStyles                   (0)
#elseif !defined FIX_GameTextStyles
	#define _FIXES_WARNING 79
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_GameTextStyles = _FIXES_DEFAULT;
	#define FIX_GameTextStyles                   _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_GameTextStyles)
	#undef FIX_GameTextStyles
	static stock FIX_GameTextStyles = 2;
	#define FIX_GameTextStyles                   (2)
#elseif FIX_GameTextStyles && !FIX_GameText
	#error FIX_GameTextStyles requires FIX_GameText
#elseif FIX_GameTextStyles
	#undef FIX_GameTextStyles
	static stock FIX_GameTextStyles = 1;
	#define FIX_GameTextStyles                   (1)
#else
	#undef FIX_GameTextStyles
	static stock FIX_GameTextStyles = 0;
	#define FIX_GameTextStyles                   (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="OnPlayerConnect">
 *     <problem>
 *         This function isn't called for players when a filterscript starts.
 *     </problem>
 *     <solution>
 *         Call it for all connected players.
 *     </solution>
 *     <see>On_FilterScriptInit</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_OnPlayerConnect
		#undef FIX_OnPlayerConnect
	#endif
	static stock FIX_OnPlayerConnect = 0;
	#define FIX_OnPlayerConnect                  (0)
#elseif !defined FIX_OnPlayerConnect
	#define _FIXES_WARNING 80
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_OnPlayerConnect = _FIXES_DEFAULT;
	#define FIX_OnPlayerConnect                  _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_OnPlayerConnect)
	#undef FIX_OnPlayerConnect
	static stock FIX_OnPlayerConnect = 2;
	#define FIX_OnPlayerConnect                  (2)
#elseif FIX_OnPlayerConnect
	#undef FIX_OnPlayerConnect
	static stock FIX_OnPlayerConnect = 1;
	#define FIX_OnPlayerConnect                  (1)
#else
	#undef FIX_OnPlayerConnect
	static stock FIX_OnPlayerConnect = 0;
	#define FIX_OnPlayerConnect                  (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="OnPlayerDisconnect">
 *     <problem>
 *         This function isn't called for players when a filterscript ends.
 *     </problem>
 *     <solution>
 *         Call it for all connected players.
 *     </solution>
 *     <see>On_FilterScriptExit</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_OnPlayerDisconnect
		#undef FIX_OnPlayerDisconnect
	#endif
	static stock FIX_OnPlayerDisconnect = 0;
	#define FIX_OnPlayerDisconnect               (0)
#elseif !defined FIX_OnPlayerDisconnect
	#define _FIXES_WARNING 81
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_OnPlayerDisconnect = _FIXES_DEFAULT;
	#define FIX_OnPlayerDisconnect               _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_OnPlayerDisconnect)
	#undef FIX_OnPlayerDisconnect
	static stock FIX_OnPlayerDisconnect = 2;
	#define FIX_OnPlayerDisconnect               (2)
#elseif FIX_OnPlayerDisconnect
	#undef FIX_OnPlayerDisconnect
	static stock FIX_OnPlayerDisconnect = 1;
	#define FIX_OnPlayerDisconnect               (1)
#else
	#undef FIX_OnPlayerDisconnect
	static stock FIX_OnPlayerDisconnect = 0;
	#define FIX_OnPlayerDisconnect               (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="CreatePlayerTextDraw">
 *     <problem>
 *         Crashes on a blank string.
 *     </problem>
 *     <solution>
 *         Intercept blank strings.
 *     </solution>
 *     <see>FIXES_CreatePlayerTextDraw</see>
 *     <author    >wups</author>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_CreatePlayerTextDraw
		#undef FIX_CreatePlayerTextDraw
	#endif
	static stock FIX_CreatePlayerTextDraw = 0;
	#define FIX_CreatePlayerTextDraw             (0)
#elseif !defined FIX_CreatePlayerTextDraw
	#define _FIXES_WARNING 82
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_CreatePlayerTextDraw = _FIXES_DEFAULT;
	#define FIX_CreatePlayerTextDraw             _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_CreatePlayerTextDraw)
	#undef FIX_CreatePlayerTextDraw
	static stock FIX_CreatePlayerTextDraw = 2;
	#define FIX_CreatePlayerTextDraw             (2)
#elseif FIX_CreatePlayerTextDraw
	#undef FIX_CreatePlayerTextDraw
	static stock FIX_CreatePlayerTextDraw = 1;
	#define FIX_CreatePlayerTextDraw             (1)
#else
	#undef FIX_CreatePlayerTextDraw
	static stock FIX_CreatePlayerTextDraw = 0;
	#define FIX_CreatePlayerTextDraw             (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="CreatePlayerTextDraw_2">
 *     <problem>
 *         If the last character in the text is a space (" "), the text will all
 *         be blank.
 *     </problem>
 *     <solution>
 *         Remove space characters from the end of the string.
 *     </solution>
 *     <see>FIXES_CreatePlayerTextDraw</see>
 *     <author    href="https://github.com/ziggi/" >ziggi</author>
 *     <post      href="https://github.com/Open-GTO/sa-mp-fixes/issues/55" />
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_CreatePlayerTextDraw_2
		#undef FIX_CreatePlayerTextDraw_2
	#endif
	static stock FIX_CreatePlayerTextDraw_2 = 0;
	#define FIX_CreatePlayerTextDraw_2           (0)
#elseif !defined FIX_CreatePlayerTextDraw_2
	#define _FIXES_WARNING 83
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_CreatePlayerTextDraw_2 = _FIXES_DEFAULT;
	#define FIX_CreatePlayerTextDraw_2           _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_CreatePlayerTextDraw_2)
	#undef FIX_CreatePlayerTextDraw_2
	static stock FIX_CreatePlayerTextDraw_2 = 2;
	#define FIX_CreatePlayerTextDraw_2           (2)
#elseif FIX_CreatePlayerTextDraw_2
	#undef FIX_CreatePlayerTextDraw_2
	static stock FIX_CreatePlayerTextDraw_2 = 1;
	#define FIX_CreatePlayerTextDraw_2           (1)
#else
	#undef FIX_CreatePlayerTextDraw_2
	static stock FIX_CreatePlayerTextDraw_2 = 0;
	#define FIX_CreatePlayerTextDraw_2           (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="PlayerTextDrawSetString">
 *     <problem>
 *         Crashes on a blank string and size greater than 1024.
 *     </problem>
 *     <solution>
 *         Intercept blank strings and truncate long strings.
 *     </solution>
 *     <see>FIXES_PlayerTextDrawSetString</see>
 *     <author    >TomTrox</author>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_PlayerTextDrawSetString
		#undef FIX_PlayerTextDrawSetString
	#endif
	static stock FIX_PlayerTextDrawSetString = 0;
	#define FIX_PlayerTextDrawSetString          (0)
#elseif !defined FIX_PlayerTextDrawSetString
	#define _FIXES_WARNING 84
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_PlayerTextDrawSetString = _FIXES_DEFAULT;
	#define FIX_PlayerTextDrawSetString        _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_PlayerTextDrawSetString)
	#undef FIX_PlayerTextDrawSetString
	static stock FIX_PlayerTextDrawSetString = 2;
	#define FIX_PlayerTextDrawSetString        (2)
#elseif FIX_PlayerTextDrawSetString
	#undef FIX_PlayerTextDrawSetString
	static stock FIX_PlayerTextDrawSetString = 1;
	#define FIX_PlayerTextDrawSetString        (1)
#else
	#undef FIX_PlayerTextDrawSetString
	static stock FIX_PlayerTextDrawSetString = 0;
	#define FIX_PlayerTextDrawSetString        (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="PlayerTextDrawSetString_2">
 *     <problem>
 *         If the last character in the text is a space (" "), the text will all
 *         be blank.
 *     </problem>
 *     <solution>
 *         Remove space characters from the end of the string.
 *     </solution>
 *     <see>FIXES_PlayerTextDrawSetString</see>
 *     <author    href="https://github.com/ziggi/" >ziggi</author>
 *     <post      href="https://github.com/Open-GTO/sa-mp-fixes/issues/55" />
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_PlayerTextDrawSetString_2
		#undef FIX_PlayerTextDrawSetString_2
	#endif
	static stock FIX_PlayerTextDrawSetString_2 = 0;
	#define FIX_PlayerTextDrawSetString_2        (0)
#elseif !defined FIX_PlayerTextDrawSetString_2
	#define _FIXES_WARNING 85
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_PlayerTextDrawSetString_2 = _FIXES_DEFAULT;
	#define FIX_PlayerTextDrawSetString_2          _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_PlayerTextDrawSetString_2)
	#undef FIX_PlayerTextDrawSetString_2
	static stock FIX_PlayerTextDrawSetString_2 = 2;
	#define FIX_PlayerTextDrawSetString_2        (2)
#elseif FIX_PlayerTextDrawSetString_2
	#undef FIX_PlayerTextDrawSetString_2
	static stock FIX_PlayerTextDrawSetString_2 = 1;
	#define FIX_PlayerTextDrawSetString_2        (1)
#else
	#undef FIX_PlayerTextDrawSetString_2
	static stock FIX_PlayerTextDrawSetString_2 = 0;
	#define FIX_PlayerTextDrawSetString_2        (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="SetPlayerCamera">
 *     <problem>
 *         Using the camera functions directly after enabling spectator mode
 *         doesn't work.
 *     </problem>
 *     <solution>
 *         Defer them.
 *     </solution>
 *     <see>FIXES_SetPlayerCameraPos</see>
 *     <see>FIXES_SetPlayerCameraLookAt</see>
 *     <see>FIXES_TogglePlayerSpectating</see>
 *     <author    href="https://github.com/emmet-jones" >Emmet_</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_SetPlayerCamera
		#undef FIX_SetPlayerCamera
	#endif
	static stock FIX_SetPlayerCamera = 0;
	#define FIX_SetPlayerCamera                  (0)
#elseif !defined FIX_SetPlayerCamera
	#define _FIXES_WARNING 86
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_SetPlayerCamera = _FIXES_DEFAULT;
	#define FIX_SetPlayerCamera                  _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_SetPlayerCamera)
	#undef FIX_SetPlayerCamera
	static stock FIX_SetPlayerCamera = 2;
	#define FIX_SetPlayerCamera                  (2)
#elseif FIX_SetPlayerCamera
	#undef FIX_SetPlayerCamera
	static stock FIX_SetPlayerCamera = 1;
	#define FIX_SetPlayerCamera                  (1)
#else
	#undef FIX_SetPlayerCamera
	static stock FIX_SetPlayerCamera = 0;
	#define FIX_SetPlayerCamera                  (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="SetPlayerTime">
 *     <problem>
 *         Using this function under "OnPlayerConnect" doesn't work.
 *     </problem>
 *     <solution>
 *         Defer it.
 *     </solution>
 *     <see>FIXES_SetPlayerTime</see>
 *     <author    href="https://github.com/emmet-jones" >Emmet_</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_SetPlayerTime
		#undef FIX_SetPlayerTime
	#endif
	static stock FIX_SetPlayerTime = 0;
	#define FIX_SetPlayerTime                    (0)
#elseif !defined FIX_SetPlayerTime
	#define _FIXES_WARNING 87
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_SetPlayerTime = _FIXES_DEFAULT;
	#define FIX_SetPlayerTime                    _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_SetPlayerTime)
	#undef FIX_SetPlayerTime
	static stock FIX_SetPlayerTime = 2;
	#define FIX_SetPlayerTime                    (2)
#elseif FIX_SetPlayerTime
	#undef FIX_SetPlayerTime
	static stock FIX_SetPlayerTime = 1;
	#define FIX_SetPlayerTime                    (1)
#else
	#undef FIX_SetPlayerTime
	static stock FIX_SetPlayerTime = 0;
	#define FIX_SetPlayerTime                    (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="OnPlayerRequestClass">
 *     <problem>
 *         Random blunts and bottles sometimes appear in class selection.
 *     </problem>
 *     <solution>
 *         Call "RemoveBuildingForPlayer".
 *     </solution>
 *     <see>OnPlayerRequestClass</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_OnPlayerRequestClass
		#undef FIX_OnPlayerRequestClass
	#endif
	static stock FIX_OnPlayerRequestClass = 0;
	#define FIX_OnPlayerRequestClass             (0)
#elseif !defined FIX_OnPlayerRequestClass
	#define _FIXES_WARNING 88
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_OnPlayerRequestClass = _FIXES_DEFAULT;
	#define FIX_OnPlayerRequestClass             _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_OnPlayerRequestClass)
	#undef FIX_OnPlayerRequestClass
	static stock FIX_OnPlayerRequestClass = 2;
	#define FIX_OnPlayerRequestClass             (2)
#elseif FIX_OnPlayerRequestClass
	#undef FIX_OnPlayerRequestClass
	static stock FIX_OnPlayerRequestClass = 1;
	#define FIX_OnPlayerRequestClass             (1)
#else
	#undef FIX_OnPlayerRequestClass
	static stock FIX_OnPlayerRequestClass = 0;
	#define FIX_OnPlayerRequestClass             (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="SetPlayerColour">
 *     <problem>
 *         If used under OnPlayerConnect, the affecting player will not see the
 *         color in the TAB menu.
 *     </problem>
 *     <solution>
 *         Defer it.
 *     </solution>
 *     <see>FIXES_SetPlayerColor</see>
 *     <author    href="https://github.com/emmet-jones" >Emmet_</author>
 *     <post      href="https://sampforum.blast.hk/showthread.php?tid=452407" />
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_SetPlayerColour
		#undef FIX_SetPlayerColour
	#endif
	static stock FIX_SetPlayerColour = 0;
	#define FIX_SetPlayerColour                  (0)
#elseif !defined FIX_SetPlayerColour
	#if defined FIX_SetPlayerColor
		#if _FIXES_IS_UNSET(FIX_SetPlayerColor)
			_FIXES_CONST_PAWNDOC(FIX_SetPlayerColour = 2);
			#define FIX_SetPlayerColour          (2)
		#else
			_FIXES_CONST_PAWNDOC(FIX_SetPlayerColour = FIX_SetPlayerColor);
			#define FIX_SetPlayerColour          (FIX_SetPlayerColor)
		#endif
	#else
		#define _FIXES_WARNING 89
		#tryinclude "_fixes_options"
		#undef _FIXES_WARNING
		static _FIXES_OPTION FIX_SetPlayerColour = _FIXES_DEFAULT;
		#define FIX_SetPlayerColour              _FIXES_DEFAULT
	#endif
#elseif _FIXES_IS_UNSET(FIX_SetPlayerColour)
	#undef FIX_SetPlayerColour
	static stock FIX_SetPlayerColour = 2;
	#define FIX_SetPlayerColour                  (2)
#elseif FIX_SetPlayerColour
	#undef FIX_SetPlayerColour
	static stock FIX_SetPlayerColour = 1;
	#define FIX_SetPlayerColour                  (1)
#else
	#undef FIX_SetPlayerColour
	static stock FIX_SetPlayerColour = 0;
	#define FIX_SetPlayerColour                  (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="FileMaths">
 *     <problem>
 *         You can write gibberish like "File:a; ++a;".
 *     </problem>
 *     <solution>
 *         Remove the operators.
 *     </solution>
 *     <see>File:operator</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 */

#if !defined FIX_FileMaths
	#define _FIXES_WARNING 90
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_FileMaths = _FIXES_DEFAULT;
	#define FIX_FileMaths                        _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_FileMaths)
	#undef FIX_FileMaths
	static stock FIX_FileMaths = 2;
	#define FIX_FileMaths                        (2)
#elseif FIX_FileMaths
	#undef FIX_FileMaths
	static stock FIX_FileMaths = 1;
	#define FIX_FileMaths                        (1)
#else
	#undef FIX_FileMaths
	static stock FIX_FileMaths = 0;
	#define FIX_FileMaths                        (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="GetPlayerWeaponData">
 *     <problem>
 *         Old weapons with no ammo left are still returned.
 *     </problem>
 *     <solution>
 *         Set "weapons" to 0.
 *     </solution>
 *     <see>FIXES_GetPlayerWeaponData</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 *     <post      href="https://sampforum.blast.hk/showthread.php?tid=567400" />
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_GetPlayerWeaponData
		#undef FIX_GetPlayerWeaponData
	#endif
	static stock FIX_GetPlayerWeaponData = 0;
	#define FIX_GetPlayerWeaponData              (0)
#elseif !defined FIX_GetPlayerWeaponData
	#define _FIXES_WARNING 91
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_GetPlayerWeaponData = _FIXES_DEFAULT;
	#define FIX_GetPlayerWeaponData              _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_GetPlayerWeaponData)
	#undef FIX_GetPlayerWeaponData
	static stock FIX_GetPlayerWeaponData = 2;
	#define FIX_GetPlayerWeaponData              (2)
#elseif FIX_GetPlayerWeaponData
	#undef FIX_GetPlayerWeaponData
	static stock FIX_GetPlayerWeaponData = 1;
	#define FIX_GetPlayerWeaponData              (1)
#else
	#undef FIX_GetPlayerWeaponData
	static stock FIX_GetPlayerWeaponData = 0;
	#define FIX_GetPlayerWeaponData              (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="strcmp">
 *     <problem>
 *         Return 0 if anyone of the string is empty.
 *     </problem>
 *     <solution>
 *         Add a check for empty string.
 *     </solution>
 *     <see>FIXES_strcmp</see>
 *     <author    href="https://github.com/Y-Less" >Y_Less</author>
 * </fix>
 */

#if !defined FIX_strcmp
	#define _FIXES_WARNING 92
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_strcmp = _FIXES_DEFAULT;
	#define FIX_strcmp                           _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_strcmp)
	#undef FIX_strcmp
	static stock FIX_strcmp = 2;
	#define FIX_strcmp                           (2)
#elseif FIX_strcmp
	#undef FIX_strcmp
	static stock FIX_strcmp = 1;
	#define FIX_strcmp                           (1)
#else
	#undef FIX_strcmp
	static stock FIX_strcmp = 0;
	#define FIX_strcmp                           (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="GetPVarString">
 *     <problem>
 *         Wrong symbol code for symbols with code 128 and above.
 *     </problem>
 *     <solution>
 *         Use logical conjunction on symbol and 0xFF.
 *     </solution>
 *     <see>FIXES_GetPVarString</see>
 *     <author    href="https://github.com/ziggi" >ziggi</author>
 *     <author    >Mutha_X</author>
 *     <author    href="https://github.com/Daniel-Cortez" >Daniel_Cortez</author>
 *     <post      href="https://sampforum.blast.hk/showthread.php?tid=572724&amp;page=2" />
 *     <post      href="http://pro-pawn.ru/showthread.php?13007" />
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_GetPVarString
		#undef FIX_GetPVarString
	#endif
	static stock FIX_GetPVarString = 0;
	#define FIX_GetPVarString                    (0)
#elseif !defined FIX_GetPVarString
	#define _FIXES_WARNING 93
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_GetPVarString = _FIXES_DEFAULT;
	#define FIX_GetPVarString                    _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_GetPVarString)
	#undef FIX_GetPVarString
	static stock FIX_GetPVarString = 2;
	#define FIX_GetPVarString                    (2)
#elseif FIX_GetPVarString
	#undef FIX_GetPVarString
	static stock FIX_GetPVarString = 1;
	#define FIX_GetPVarString                    (1)
#else
	#undef FIX_GetPVarString
	static stock FIX_GetPVarString = 0;
	#define FIX_GetPVarString                    (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="GetSVarString">
 *     <problem>
 *         Wrong symbol code for symbols with code 128 and above.
 *     </problem>
 *     <solution>
 *         Use logical conjunction on symbol and 0xFF.
 *     </solution>
 *     <see>FIXES_GetSVarString</see>
 *     <author    href="https://github.com/ziggi" >ziggi</author>
 *     <author    >Mutha_X</author>
 *     <author    href="https://github.com/Daniel-Cortez" >Daniel_Cortez</author>
 *     <post      href="https://sampforum.blast.hk/showthread.php?tid=572724&amp;page=2" />
 *     <post      href="http://pro-pawn.ru/showthread.php?13007" />
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_GetSVarString
		#undef FIX_GetSVarString
	#endif
	static stock FIX_GetSVarString = 0;
	#define FIX_GetSVarString                    (0)
#elseif !defined FIX_GetSVarString
	#define _FIXES_WARNING 94
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_GetSVarString = _FIXES_DEFAULT;
	#define FIX_GetSVarString                    _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_GetSVarString)
	#undef FIX_GetSVarString
	static stock FIX_GetSVarString = 2;
	#define FIX_GetSVarString                    (2)
#elseif FIX_GetSVarString
	#undef FIX_GetSVarString
	static stock FIX_GetSVarString = 1;
	#define FIX_GetSVarString                    (1)
#else
	#undef FIX_GetSVarString
	static stock FIX_GetSVarString = 0;
	#define FIX_GetSVarString                    (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="toupper">
 *     <problem>
 *         Not working on Linux for symbols with code 128 and above.
 *     </problem>
 *     <solution>
 *         Recreate the function.
 *     </solution>
 *     <see>FIXES_toupper</see>
 *     <author    href="https://github.com/ziggi" >ziggi</author>
 *     <post      href="http://pro-pawn.ru/showthread.php?13466&amp;p=72954#post72954" />
 * </fix>
 */

#if !defined FIX_toupper
	#define _FIXES_WARNING 95
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_toupper = _FIXES_DEFAULT;
	#define FIX_toupper                          _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_toupper)
	#undef FIX_toupper
	static stock FIX_toupper = 2;
	#define FIX_toupper                          (2)
#elseif FIX_toupper
	#undef FIX_toupper
	static stock FIX_toupper = 1;
	#define FIX_toupper                          (1)
#else
	#undef FIX_toupper
	static stock FIX_toupper = 0;
	#define FIX_toupper                          (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="tolower">
 *     <problem>
 *         Not working on Linux for symbols with code 128 and above.
 *     </problem>
 *     <solution>
 *         Recreate the function.
 *     </solution>
 *     <see>FIXES_tolower</see>
 *     <author    href="https://github.com/ziggi" >ziggi</author>
 *     <post      href="http://pro-pawn.ru/showthread.php?13466&amp;p=72954#post72954" />
 * </fix>
 */

#if !defined FIX_tolower
	#define _FIXES_WARNING 96
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_tolower = _FIXES_DEFAULT;
	#define FIX_tolower                          _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_tolower)
	#undef FIX_tolower
	static stock FIX_tolower = 2;
	#define FIX_tolower                          (2)
#elseif FIX_tolower
	#undef FIX_tolower
	static stock FIX_tolower = 1;
	#define FIX_tolower                          (1)
#else
	#undef FIX_tolower
	static stock FIX_tolower = 0;
	#define FIX_tolower                          (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="ispacked">
 *     <problem>
 *         Returns false when the string is packed and starts with a symbol
 *         with code 128 and above.
 *     </problem>
 *     <solution>
 *         Check the string manually.
 *     </solution>
 *     <see>FIXES_ispacked</see>
 *     <author    href="https://github.com/Daniel-Cortez" >Daniel_Cortez</author>
 *     <author    href="https://github.com/VVWVV" >VVWVV</author>
 * </fix>
 */

#if !defined FIX_ispacked
	#define _FIXES_WARNING 97
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_ispacked = _FIXES_DEFAULT;
	#define FIX_ispacked                         _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_ispacked)
	#undef FIX_ispacked
	static stock FIX_ispacked = 2;
	#define FIX_ispacked                         (2)
#elseif FIX_ispacked
	#undef FIX_ispacked
	static stock FIX_ispacked = 1;
	#define FIX_ispacked                         (1)
#else
	#undef FIX_ispacked
	static stock FIX_ispacked = 0;
	#define FIX_ispacked                         (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="PassengerSeating">
 *     <problem>
 *         Teleporting player to passenger seat after delay.
 *     </problem>
 *     <solution>
 *         Call ClearAnimation after some delay.
 *     </solution>
 *     <see>OnPlayerEnterVehicle</see>
 *     <see>OnPlayerStateChange</see>
 *     <author    href="https://github.com/ziggi" >ziggi</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_PassengerSeating
		#undef FIX_PassengerSeating
	#endif
	static stock FIX_PassengerSeating = 0;
	#define FIX_PassengerSeating                 (0)
#elseif !defined FIX_PassengerSeating
	#define _FIXES_WARNING 98
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_PassengerSeating = _FIXES_DEFAULT;
	#define FIX_PassengerSeating                 _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_PassengerSeating)
	#undef FIX_PassengerSeating
	static stock FIX_PassengerSeating = 2;
	#define FIX_PassengerSeating                 (2)
#elseif FIX_PassengerSeating
	#undef FIX_PassengerSeating
	static stock FIX_PassengerSeating = 1;
	#define FIX_PassengerSeating                 (1)
#else
	#undef FIX_PassengerSeating
	static stock FIX_PassengerSeating = 0;
	#define FIX_PassengerSeating                 (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="GogglesSync">
 *     <problem>
 *         Visual effects show for all players.
 *     </problem>
 *     <solution>
 *         return 0 in OnPlayerUpdate after key pressed.
 *     </solution>
 *     <see>OnPlayerUpdate</see>
 *     <author    href="https://github.com/ziggi" >ziggi</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_GogglesSync
		#undef FIX_GogglesSync
	#endif
	static stock FIX_GogglesSync = 0;
	#define FIX_GogglesSync                      (0)
#elseif !defined FIX_GogglesSync
	#define _FIXES_WARNING 99
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_GogglesSync = _FIXES_DEFAULT;
	#define FIX_GogglesSync                      _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_GogglesSync)
	#undef FIX_GogglesSync
	static stock FIX_GogglesSync = 2;
	#define FIX_GogglesSync                      (2)
#elseif FIX_GogglesSync
	#undef FIX_GogglesSync
	static stock FIX_GogglesSync = 1;
	#define FIX_GogglesSync                      (1)
#else
	#undef FIX_GogglesSync
	static stock FIX_GogglesSync = 0;
	#define FIX_GogglesSync                      (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="GetPlayerPoolSize">
 *     <problem>
 *         Returns "0" even if there are no players on the server.
 *     </problem>
 *     <solution>
 *         Return "-1" if PlayerPoolsize is 0 but Player 0 is not connected.
 *     </solution>
 *     <see>FIXES_GetPlayerPoolSize</see>
 *     <author    href="https://github.com/Bios-Marcel" >Bios-Marcel</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_GetPlayerPoolSize
		#undef FIX_GetPlayerPoolSize
	#endif
	static stock FIX_GetPlayerPoolSize = 0;
	#define FIX_GetPlayerPoolSize                (0)
#elseif !defined FIX_GetPlayerPoolSize
	#define _FIXES_WARNING 100
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_GetPlayerPoolSize = _FIXES_DEFAULT;
	#define FIX_GetPlayerPoolSize                _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_GetPlayerPoolSize)
	#undef FIX_GetPlayerPoolSize
	static stock FIX_GetPlayerPoolSize = 2;
	#define FIX_GetPlayerPoolSize                (2)
#elseif FIX_GetPlayerPoolSize
	#undef FIX_GetPlayerPoolSize
	static stock FIX_GetPlayerPoolSize = 1;
	#define FIX_GetPlayerPoolSize                (1)
#else
	#undef FIX_GetPlayerPoolSize
	static stock FIX_GetPlayerPoolSize = 0;
	#define FIX_GetPlayerPoolSize                (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="SetPlayerPos">
 *     <problem>
 *         Using this function on skydiving players kills them.
 *     </problem>
 *     <solution>
 *         Remove the parachute when the player is skydiving.
 *     </solution>
 *     <see>FIXES_SetPlayerPos</see>
 *     <see>FIXES_SetPlayerPosFindZ</see>
 *     <author    href="https://github.com/WoutProvost" >Freaksken</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_SetPlayerPos
		#undef FIX_SetPlayerPos
	#endif
	static stock FIX_SetPlayerPos = 0;
	#define FIX_SetPlayerPos                     (0)
#elseif !defined FIX_SetPlayerPos
	#define _FIXES_WARNING 101
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_SetPlayerPos = _FIXES_DEFAULT;
	#define FIX_SetPlayerPos                     _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_SetPlayerPos)
	#undef FIX_SetPlayerPos
	static stock FIX_SetPlayerPos = 2;
	#define FIX_SetPlayerPos                     (2)
#elseif FIX_SetPlayerPos
	#undef FIX_SetPlayerPos
	static stock FIX_SetPlayerPos = 1;
	#define FIX_SetPlayerPos                     (1)
#else
	#undef FIX_SetPlayerPos
	static stock FIX_SetPlayerPos = 0;
	#define FIX_SetPlayerPos                     (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="GetPlayerAmmo">
 *     <problem>
 *         Returns erroneous values over 32767 and under -32768 due to overflow.
 *     </problem>
 *     <solution>
 *         Prevent setting or adding ammo above 32767 and setting or removing
 *         ammo below 0.
 *     </solution>
 *     <see>FIXES_SetPlayerAmmo</see>
 *     <see>FIXES_GivePlayerWeapon</see>
 *     <author    href="https://github.com/WoutProvost" >Freaksken</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_GetPlayerAmmo
		#undef FIX_GetPlayerAmmo
	#endif
	static stock FIX_GetPlayerAmmo = 0;
	#define FIX_GetPlayerAmmo                    (0)
#elseif !defined FIX_GetPlayerAmmo
	#define _FIXES_WARNING 102
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_GetPlayerAmmo = _FIXES_DEFAULT;
	#define FIX_GetPlayerAmmo                    _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_GetPlayerAmmo)
	#undef FIX_GetPlayerAmmo
	static stock FIX_GetPlayerAmmo = 2;
	#define FIX_GetPlayerAmmo                    (2)
#elseif FIX_GetPlayerAmmo
	#undef FIX_GetPlayerAmmo
	static stock FIX_GetPlayerAmmo = 1;
	#define FIX_GetPlayerAmmo                    (1)
#else
	#undef FIX_GetPlayerAmmo
	static stock FIX_GetPlayerAmmo = 0;
	#define FIX_GetPlayerAmmo                    (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="JIT">
 *     <problem>
 *         Can't easily determine if the script is JIT compiled.
 *     </problem>
 *     <solution>
 *         Provide "IS_JIT" to the script for tests.
 *     </solution>
 *     <see>OnJITCompile</see>
 *     <author    href="https://github.com/Y-Less" >Y_Less</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_JIT
		#undef FIX_JIT
	#endif
	static stock FIX_JIT = 0;
	#define FIX_JIT                          (0)
#elseif !defined FIX_JIT
	#define _FIXES_WARNING 103
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_JIT = _FIXES_DEFAULT;
	#define FIX_JIT                              _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_JIT)
	#undef FIX_JIT
	static stock FIX_JIT = 2;
	#define FIX_JIT                              (2)
#elseif FIX_JIT
	#undef FIX_JIT
	static stock FIX_JIT = 1;
	#define FIX_JIT                              (1)
#else
	#undef FIX_JIT
	static stock FIX_JIT = 0;
	#define FIX_JIT                              (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="OS">
 *     <problem>
 *         Can't easily determine what OS the script is running on.
 *     </problem>
 *     <solution>
 *         Provide "IS_WINDOWS" and "IS_LINUX" to the script for tests.
 *     </solution>
 *     <see>_FIXES_DetermineOS</see>
 *     <author    href="https://github.com/Y-Less" >Y_Less</author>
 * </fix>
 */

#if !defined FIX_OS
	#define _FIXES_WARNING 104
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_OS = _FIXES_DEFAULT;
	#define FIX_OS                               _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_OS)
	#undef FIX_OS
	static stock FIX_OS = 2;
	#define FIX_OS                               (2)
#elseif FIX_OS
	#undef FIX_OS
	static stock FIX_OS = 1;
	#define FIX_OS                               (1)
#else
	#undef FIX_OS
	static stock FIX_OS = 0;
	#define FIX_OS                               (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="const">
 *     <problem>
 *         Some SA-MP natives don't use "const" when they could.
 *     </problem>
 *     <solution>
 *         Redefine the natives.
 *     </solution>
 *     <see>FIX_const</see>
 *     <author    href="https://github.com/Y-Less" >Y_Less</author>
 * </fix>
 */

#if !defined FIX_const
	#define _FIXES_WARNING 105
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_const = _FIXES_DEFAULT;
	#define FIX_const                            _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_const)
	#undef FIX_const
	static stock FIX_const = 2;
	#define FIX_const                            (2)
#elseif FIX_const
	#undef FIX_const
	static stock FIX_const = 1;
	#define FIX_const                            (1)
#else
	#undef FIX_const
	static stock FIX_const = 0;
	#define FIX_const                            (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="VEHICLES">
 *     <problem>
 *         The vehicle models IDs are not defined by default.
 *     </problem>
 *     <solution>
 *         Define them.
 *     </solution>
 *     <author    href="https://github.com/IstuntmanI" >stuntman</author>
 * </fix>
 */

#if !defined FIX_VEHICLES
	#if defined VEHICLE_INFERNUS
		#if FIXES_EnableDeprecated
			#define _FIXES_WARNING 106
			#tryinclude "_fixes_options"
			#undef _FIXES_WARNING
			static _FIXES_OPTION FIX_VEHICLES = FIXES_EnableDeprecated;
		#else
			_FIXES_CONST_PAWNDOC(FIX_VEHICLES = FIXES_EnableDeprecated);
		#endif
		#define FIX_VEHICLES                     FIXES_EnableDeprecated
	#else
		#define _FIXES_WARNING 106
		#tryinclude "_fixes_options"
		#undef _FIXES_WARNING
		static _FIXES_OPTION FIX_VEHICLES = _FIXES_DEFAULT;
		#define FIX_VEHICLES                     _FIXES_DEFAULT
	#endif
#elseif _FIXES_IS_UNSET(FIX_VEHICLES)
	#undef FIX_VEHICLES
	static stock FIX_VEHICLES = 2;
	#define FIX_VEHICLES                         (2)
#elseif FIX_VEHICLES
	#undef FIX_VEHICLES
	static stock FIX_VEHICLES = 1;
	#define FIX_VEHICLES                         (1)
#else
	#undef FIX_VEHICLES
	static stock FIX_VEHICLES = 0;
	#define FIX_VEHICLES                         (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="GetPlayerWeather" disabled="true">
 *     <problem>
 *         This function doesn't exist.
 *     </problem>
 *     <solution>
 *         Add it.
 *     </solution>
 *     <see>FIXES_GetPlayerWeather</see>
 *     <author    href="https://github.com/IstuntmanI/" >IstuntmanI</author>
 *     <author    href="https://github.com/ziggi/" >ziggi</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_GetPlayerWeather
		#undef FIX_GetPlayerWeather
	#endif
	static stock FIX_GetPlayerWeather = 0;
	#define FIX_GetPlayerWeather                 (0)
#elseif !defined FIX_GetPlayerWeather
	#if defined GetPlayerWeather
		#if FIXES_EnableDeprecated
			#define _FIXES_WARNING 107
			#tryinclude "_fixes_options"
			#undef _FIXES_WARNING
			static _FIXES_OPTION FIX_GetPlayerWeather = FIXES_EnableDeprecated;
		#else
			_FIXES_CONST_PAWNDOC(FIX_GetPlayerWeather = FIXES_EnableDeprecated);
		#endif
		#define FIX_GetPlayerWeather             FIXES_EnableDeprecated
	#else
		#define _FIXES_WARNING 107
		#tryinclude "_fixes_options"
		#undef _FIXES_WARNING
		static _FIXES_OPTION FIX_GetPlayerWeather = FIX_API;
		#define FIX_GetPlayerWeather             FIX_API
	#endif
#elseif _FIXES_IS_UNSET(FIX_GetPlayerWeather)
	#undef FIX_GetPlayerWeather
	static stock FIX_GetPlayerWeather = 2;
	#define FIX_GetPlayerWeather                 (2)
#elseif FIX_GetPlayerWeather
	#undef FIX_GetPlayerWeather
	static stock FIX_GetPlayerWeather = 1;
	#define FIX_GetPlayerWeather                 (1)
#else
	#undef FIX_GetPlayerWeather
	static stock FIX_GetPlayerWeather = 0;
	#define FIX_GetPlayerWeather                 (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="GetWeather" disabled="true">
 *     <problem>
 *         This function doesn't exist.
 *     </problem>
 *     <solution>
 *         Add it.
 *     </solution>
 *     <see>FIXES_GetWeather</see>
 *     <author    href="https://github.com/IstuntmanI/" >IstuntmanI</author>
 *     <author    href="https://github.com/ziggi/" >ziggi</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_GetWeather
		#undef FIX_GetWeather
	#endif
	static stock FIX_GetWeather = 0;
	#define FIX_GetWeather                       (0)
#elseif !defined FIX_GetWeather
	#if defined GetWeather
		#if FIXES_EnableDeprecated
			#define _FIXES_WARNING 108
			#tryinclude "_fixes_options"
			#undef _FIXES_WARNING
			static _FIXES_OPTION FIX_GetWeather = FIXES_EnableDeprecated;
		#else
			_FIXES_CONST_PAWNDOC(FIX_GetWeather = FIXES_EnableDeprecated);
		#endif
		#define FIX_GetWeather                   FIXES_EnableDeprecated
	#else
		#define _FIXES_WARNING 108
		#tryinclude "_fixes_options"
		#undef _FIXES_WARNING
		static _FIXES_OPTION FIX_GetWeather = FIX_API;
		#define FIX_GetWeather                   FIX_API
	#endif
#elseif _FIXES_IS_UNSET(FIX_GetWeather)
	#undef FIX_GetWeather
	static stock FIX_GetWeather = 2;
	#define FIX_GetWeather                       (2)
#elseif FIX_GetWeather
	#undef FIX_GetWeather
	static stock FIX_GetWeather = 1;
	#define FIX_GetWeather                       (1)
#else
	#undef FIX_GetWeather
	static stock FIX_GetWeather = 0;
	#define FIX_GetWeather                       (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="GetWorldTime" disabled="true">
 *     <problem>
 *         This function doesn't exist.
 *     </problem>
 *     <solution>
 *         Add it.
 *     </solution>
 *     <see>FIXES_GetWorldTime</see>
 *     <author    href="https://github.com/ziggi/" >ziggi</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_GetWorldTime
		#undef FIX_GetWorldTime
	#endif
	static stock FIX_GetWorldTime = 0;
	#define FIX_GetWorldTime                     (0)
#elseif !defined FIX_GetWorldTime
	#if defined GetWorldTime
		#if FIXES_EnableDeprecated
			#define _FIXES_WARNING 109
			#tryinclude "_fixes_options"
			#undef _FIXES_WARNING
			static _FIXES_OPTION FIX_GetWorldTime = FIXES_EnableDeprecated;
		#else
			_FIXES_CONST_PAWNDOC(FIX_GetWorldTime = FIXES_EnableDeprecated);
		#endif
		#define FIX_GetWorldTime                 FIXES_EnableDeprecated
	#else
		#define _FIXES_WARNING 109
		#tryinclude "_fixes_options"
		#undef _FIXES_WARNING
		static _FIXES_OPTION FIX_GetWorldTime = FIX_API;
		#define FIX_GetWorldTime                 FIX_API
	#endif
#elseif _FIXES_IS_UNSET(FIX_GetWorldTime)
	#undef FIX_GetWorldTime
	static stock FIX_GetWorldTime = 2;
	#define FIX_GetWorldTime                     (2)
#elseif FIX_GetWorldTime
	#undef FIX_GetWorldTime
	static stock FIX_GetWorldTime = 1;
	#define FIX_GetWorldTime                     (1)
#else
	#undef FIX_GetWorldTime
	static stock FIX_GetWorldTime = 0;
	#define FIX_GetWorldTime                     (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="GetConsoleVarAsString">
 *     <problem>
 *         Crashes on unknown string variables.
 *     </problem>
 *     <solution>
 *         Read the file manually.
 *     </solution>
 *     <see>FIXES_GetConsoleVarAsString</see>
 *     <see>FIXES_GetServerVarAsString</see>
 *     <author    href="https://github.com/Y-Less" >Y_Less</author>
 *     <post      href="https://github.com/Open-GTO/sa-mp-fixes/issues/73" />
 * </fix>
 */

#if !defined FIX_GetConsoleVarAsString
	#if defined FIX_GetServerVarAsString
		#if _FIXES_IS_UNSET(FIX_GetServerVarAsString)
			_FIXES_CONST_PAWNDOC(FIX_GetConsoleVarAsString = 2);
			#define FIX_GetConsoleVarAsString    (2)
		#else
			_FIXES_CONST_PAWNDOC(FIX_GetConsoleVarAsString = FIX_GetServerVarAsString);
			#define FIX_GetConsoleVarAsString    (FIX_GetServerVarAsString)
		#endif
	#else
		#define _FIXES_WARNING 110
		#tryinclude "_fixes_options"
		#undef _FIXES_WARNING
		static _FIXES_OPTION FIX_GetConsoleVarAsString = _FIXES_DEFAULT;
		#define FIX_GetConsoleVarAsString        _FIXES_DEFAULT
	#endif
#elseif _FIXES_IS_UNSET(FIX_GetConsoleVarAsString)
	#undef FIX_GetConsoleVarAsString
	static stock FIX_GetConsoleVarAsString = 2;
	#define FIX_GetConsoleVarAsString            (2)
#elseif FIX_GetConsoleVarAsString
	#undef FIX_GetConsoleVarAsString
	static stock FIX_GetConsoleVarAsString = 1;
	#define FIX_GetConsoleVarAsString            (1)
#else
	#undef FIX_GetConsoleVarAsString
	static stock FIX_GetConsoleVarAsString = 0;
	#define FIX_GetConsoleVarAsString            (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="GetConsoleVarAsInt">
 *     <problem>
 *         Crashes on unknown int variables.
 *     </problem>
 *     <solution>
 *         Read the file manually.
 *     </solution>
 *     <see>FIXES_GetConsoleVarAsInt</see>
 *     <see>FIXES_GetServerVarAsInt</see>
 *     <author    href="https://github.com/Y-Less" >Y_Less</author>
 *     <post      href="https://github.com/Open-GTO/sa-mp-fixes/issues/73" />
 * </fix>
 */

#if !defined FIX_GetConsoleVarAsInt
	#if defined FIX_GetServerVarAsInt
		#if _FIXES_IS_UNSET(FIX_GetServerVarAsInt)
			_FIXES_CONST_PAWNDOC(FIX_GetConsoleVarAsInt = 2);
			#define FIX_GetConsoleVarAsInt       (2)
		#else
			_FIXES_CONST_PAWNDOC(FIX_GetConsoleVarAsInt = FIX_GetServerVarAsInt);
			#define FIX_GetConsoleVarAsInt       (FIX_GetServerVarAsInt)
		#endif
	#else
		#define _FIXES_WARNING 111
		#tryinclude "_fixes_options"
		#undef _FIXES_WARNING
		static _FIXES_OPTION FIX_GetConsoleVarAsInt    = _FIXES_DEFAULT;
		#define FIX_GetConsoleVarAsInt           _FIXES_DEFAULT
	#endif
#elseif _FIXES_IS_UNSET(FIX_GetConsoleVarAsInt)
	#undef FIX_GetConsoleVarAsInt
	static stock FIX_GetConsoleVarAsInt = 2;
	#define FIX_GetConsoleVarAsInt               (2)
#elseif FIX_GetConsoleVarAsInt
	#undef FIX_GetConsoleVarAsInt
	static stock FIX_GetConsoleVarAsInt = 1;
	#define FIX_GetConsoleVarAsInt               (1)
#else
	#undef FIX_GetConsoleVarAsInt
	static stock FIX_GetConsoleVarAsInt = 0;
	#define FIX_GetConsoleVarAsInt               (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="GetConsoleVarAsBool">
 *     <problem>
 *         Crashes on unknown boolean variables.
 *     </problem>
 *     <solution>
 *         Read the file manually.
 *     </solution>
 *     <see>FIXES_GetConsoleVarAsBool</see>
 *     <see>FIXES_GetServerVarAsBool</see>
 *     <author    href="https://github.com/Y-Less" >Y_Less</author>
 *     <post      href="https://github.com/Open-GTO/sa-mp-fixes/issues/73" />
 * </fix>
 */

#if !defined FIX_GetConsoleVarAsBool
	#if defined FIX_GetServerVarAsBool
		#if _FIXES_IS_UNSET(FIX_GetServerVarAsBool)
			_FIXES_CONST_PAWNDOC(FIX_GetConsoleVarAsBool = 2);
			#define FIX_GetConsoleVarAsBool      (2)
		#else
			_FIXES_CONST_PAWNDOC(FIX_GetConsoleVarAsBool = FIX_GetServerVarAsBool);
			#define FIX_GetConsoleVarAsBool      (FIX_GetServerVarAsBool)
		#endif
	#else
		#define _FIXES_WARNING 112
		#tryinclude "_fixes_options"
		#undef _FIXES_WARNING
		static _FIXES_OPTION FIX_GetConsoleVarAsBool   = _FIXES_DEFAULT;
		#define FIX_GetConsoleVarAsBool          _FIXES_DEFAULT
	#endif
#elseif _FIXES_IS_UNSET(FIX_GetConsoleVarAsBool)
	#undef FIX_GetConsoleVarAsBool
	static stock FIX_GetConsoleVarAsBool = 2;
	#define FIX_GetConsoleVarAsBool              (2)
#elseif FIX_GetConsoleVarAsBool
	#undef FIX_GetConsoleVarAsBool
	static stock FIX_GetConsoleVarAsBool = 1;
	#define FIX_GetConsoleVarAsBool              (1)
#else
	#undef FIX_GetConsoleVarAsBool
	static stock FIX_GetConsoleVarAsBool = 0;
	#define FIX_GetConsoleVarAsBool              (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="GetConsoleVarAsFloat">
 *     <problem>
 *         Doesn't even exist.
 *     </problem>
 *     <solution>
 *         Read the file manually.
 *     </solution>
 *     <see>FIXES_GetConsoleVarAsFloat</see>
 *     <see>FIXES_GetServerVarAsFloat</see>
 *     <author    href="https://github.com/Y-Less" >Y_Less</author>
 *     <post      href="https://github.com/Open-GTO/sa-mp-fixes/issues/73" />
 * </fix>
 */

#if !defined FIX_GetConsoleVarAsFloat
	#if defined GetConsoleVarAsFloat
		#if FIX_GetConsoleVarAsString
			#define _FIXES_WARNING 113
			#tryinclude "_fixes_options"
			#undef _FIXES_WARNING
			static _FIXES_OPTION FIX_GetConsoleVarAsFloat = _FIXES_DEFAULT;
			#define FIX_GetConsoleVarAsFloat     _FIXES_DEFAULT
		#else
			#if FIXES_EnableDeprecated
				#define _FIXES_WARNING 113
				#tryinclude "_fixes_options"
				#undef _FIXES_WARNING
				static _FIXES_OPTION FIX_GetConsoleVarAsFloat = FIXES_EnableDeprecated;
			#else
				_FIXES_CONST_PAWNDOC(FIX_GetConsoleVarAsFloat = FIXES_EnableDeprecated);
			#endif
			#define FIX_GetConsoleVarAsFloat     FIXES_EnableDeprecated
		#endif
	#else
		#if defined FIX_GetServerVarAsFloat
			#if _FIXES_IS_UNSET(FIX_GetServerVarAsFloat)
				_FIXES_CONST_PAWNDOC(FIX_GetConsoleVarAsFloat = 2);
				#define FIX_GetConsoleVarAsFloat (2)
			#else
				_FIXES_CONST_PAWNDOC(FIX_GetConsoleVarAsFloat = FIX_GetServerVarAsFloat);
				#define FIX_GetConsoleVarAsFloat (FIX_GetServerVarAsFloat)
			#endif
		#else
			#define _FIXES_WARNING 113
			#tryinclude "_fixes_options"
			#undef _FIXES_WARNING
			static _FIXES_OPTION FIX_GetConsoleVarAsFloat = FIX_Natives;
			#define FIX_GetConsoleVarAsFloat     FIX_Natives
		#endif
	#endif
#elseif _FIXES_IS_UNSET(FIX_GetConsoleVarAsFloat)
	#undef FIX_GetConsoleVarAsFloat
	static stock FIX_GetConsoleVarAsFloat = 2;
	#define FIX_GetConsoleVarAsFloat             (2)
#elseif FIX_GetConsoleVarAsFloat
	#undef FIX_GetConsoleVarAsFloat
	static stock FIX_GetConsoleVarAsFloat = 1;
	#define FIX_GetConsoleVarAsFloat             (1)
#else
	#undef FIX_GetConsoleVarAsFloat
	static stock FIX_GetConsoleVarAsFloat = 0;
	#define FIX_GetConsoleVarAsFloat             (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="tabsize">
 *     <problem>
 *         Some people still use <c>tabsize 0</c>.
 *     </problem>
 *     <solution>
 *         Break the pragma.
 *     </solution>
 *     <see>_DUMMY_do_not_use_tabsize_0</see>
 *     <author    href="https://github.com/Y-Less" >Y_Less</author>
 *     <post      href="http://forum.sa-mp.com/showpost.php?p=3929000" />
 * </fix>
 */

#if !defined FIX_tabsize
	#define _FIXES_WARNING 114
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_tabsize = _FIXES_DEFAULT;
	#define FIX_tabsize                          _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_tabsize)
	#undef FIX_tabsize
	static stock FIX_tabsize = 2;
	#define FIX_tabsize                          (2)
#elseif FIX_tabsize
	#undef FIX_tabsize
	static stock FIX_tabsize = 1;
	#define FIX_tabsize                          (1)
#else
	#undef FIX_tabsize
	static stock FIX_tabsize = 0;
	#define FIX_tabsize                          (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="Callbacks">
 *     <problem>
 *         Several callbacks only work in filterscripts first.
 *     </problem>
 *     <solution>
 *         This is a single define for all those callbacks.
 *     </solution>
 *     <see>OnGameModeInit</see>
 *     <author    href="https://github.com/Y-Less" >Y_Less</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_Callbacks
		#undef FIX_Callbacks
	#endif
	static stock FIX_Callbacks = 0;
	#define FIX_Callbacks                        (0)
#elseif !defined FIX_Callbacks
	#define _FIXES_WARNING 115
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_Callbacks = _FIXES_DEFAULT;
	#define FIX_Callbacks                        _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_Callbacks)
	#undef FIX_Callbacks
	static stock FIX_Callbacks = 2;
	#define FIX_Callbacks                        (2)
#elseif FIX_Callbacks
	#undef FIX_Callbacks
	static stock FIX_Callbacks = 1;
	#define FIX_Callbacks                        (1)
#else
	#undef FIX_Callbacks
	static stock FIX_Callbacks = 0;
	#define FIX_Callbacks                        (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="OnRconCommand">
 *     <problem>
 *         Is not called in the gamemode unless first called in a filterscript.
 *     </problem>
 *     <solution>
 *         Load a minimal (embedded) FS to bootstrap it.
 *     </solution>
 *     <see>OnGameModeInit</see>
 *     <author    href="https://github.com/Y-Less" >Y_Less</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_OnRconCommand
		#undef FIX_OnRconCommand
	#endif
	static stock FIX_OnRconCommand = 0;
	#define FIX_OnRconCommand                    (0)
#elseif !defined FIX_OnRconCommand
	#define _FIXES_WARNING 116
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_OnRconCommand = FIX_Callbacks;
	#define FIX_OnRconCommand                    FIX_Callbacks
#elseif _FIXES_IS_UNSET(FIX_OnRconCommand)
	#undef FIX_OnRconCommand
	static stock FIX_OnRconCommand = 2;
	#define FIX_OnRconCommand                    (2)
#elseif FIX_OnRconCommand
	#undef FIX_OnRconCommand
	static stock FIX_OnRconCommand = 1;
	#define FIX_OnRconCommand                    (1)
#else
	#undef FIX_OnRconCommand
	static stock FIX_OnRconCommand = 0;
	#define FIX_OnRconCommand                    (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="OnClientCheckResponse">
 *     <problem>
 *         Is not called in the gamemode ever.
 *     </problem>
 *     <solution>
 *         Load a minimal (embedded) FS to bootstrap it.
 *     </solution>
 *     <see>OnGameModeInit</see>
 *     <author    href="https://github.com/Y-Less" >Y_Less</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_OnClientCheckResponse
		#undef FIX_OnClientCheckResponse
	#endif
	static stock FIX_OnClientCheckResponse = 0;
	#define FIX_OnClientCheckResponse            (0)
	#define FIXES_OnClientCheckResponse FIX_OnClientCheckResponse
#elseif !defined FIX_OnClientCheckResponse
	#define _FIXES_WARNING 117
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_OnClientCheckResponse = FIX_Callbacks;
	#define FIX_OnClientCheckResponse            FIX_Callbacks
#elseif _FIXES_IS_UNSET(FIX_OnClientCheckResponse)
	#undef FIX_OnClientCheckResponse
	static stock FIX_OnClientCheckResponse = 2;
	#define FIX_OnClientCheckResponse            (2)
#elseif FIX_OnClientCheckResponse
	#undef FIX_OnClientCheckResponse
	static stock FIX_OnClientCheckResponse = 1;
	#define FIX_OnClientCheckResponse            (1)
#else
	#undef FIX_OnClientCheckResponse
	static stock FIX_OnClientCheckResponse = 0;
	#define FIX_OnClientCheckResponse            (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="GetMaxPlayers">
 *     <problem>
 *         If this is > MAX_PLAYERS, can cause OOBs in code.
 *     </problem>
 *     <solution>
 *         Constrain it; but also warn because that doesn't really help.
 *     </solution>
 *     <see>GetMaxPlayers</see>
 *     <author href="https://github.com/Y-Less" >Y_Less</author>
 * </fix>
 */

#if !defined FIX_GetMaxPlayers
	#define _FIXES_WARNING 118
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_GetMaxPlayers = _FIXES_DEFAULT;
	#define FIX_GetMaxPlayers                    _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_GetMaxPlayers)
	#undef FIX_GetMaxPlayers
	static stock FIX_GetMaxPlayers = 2;
	#define FIX_GetMaxPlayers                    (2)
#elseif FIX_GetMaxPlayers
	#undef FIX_GetMaxPlayers
	static stock FIX_GetMaxPlayers = 1;
	#define FIX_GetMaxPlayers                    (1)
#else
	#undef FIX_GetMaxPlayers
	static stock FIX_GetMaxPlayers = 0;
	#define FIX_GetMaxPlayers                    (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="BypassDialog">
 *     <problem>
 *         You can type commands and move while in dialogs.
 *     </problem>
 *     <solution>
 *         Return 0.
 *     </solution>
 *     <see>OnPlayerCommandText</see>
 *     <see>OnPlayerText</see>
 *     <see>OnPlayerUpdate</see>
 *     <see>OnDialogResponse</see>
 *     <author href="https://github.com/Y-Less" >Y_Less</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_BypassDialog
		#undef FIX_BypassDialog
	#endif
	static stock FIX_BypassDialog = 0;
	#define FIX_BypassDialog                     (0)
#elseif !defined FIX_BypassDialog
	#define _FIXES_WARNING 119
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_BypassDialog = _FIXES_DEFAULT;
	#define FIX_BypassDialog                     _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_BypassDialog)
	#undef FIX_BypassDialog
	static stock FIX_BypassDialog = 2;
	#define FIX_BypassDialog                     (2)
#elseif FIX_BypassDialog
	#undef FIX_BypassDialog
	static stock FIX_BypassDialog = 1;
	#define FIX_BypassDialog                     (1)
#else
	#undef FIX_BypassDialog
	static stock FIX_BypassDialog = 0;
	#define FIX_BypassDialog                     (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="SetTimer">
 *     <problem>
 *         Valid timers can return ID 0.
 *     </problem>
 *     <solution>
 *         Recreate them and kill the original.
 *     </solution>
 *     <see>FIXES_SetTimer</see>
 *     <see>FIXES_SetTimerEx</see>
 *     <author href="https://github.com/Y-Less" >Y_Less</author>
 * </fix>
 */

#if !defined FIX_SetTimer
	#define _FIXES_WARNING 120
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_SetTimer = _FIXES_DEFAULT;
	#define FIX_SetTimer                         _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_SetTimer)
	#undef FIX_SetTimer
	static stock FIX_SetTimer = 2;
	#define FIX_SetTimer                         (2)
#elseif FIX_SetTimer
	#undef FIX_SetTimer
	static stock FIX_SetTimer = 1;
	#define FIX_SetTimer                         (1)
#else
	#undef FIX_SetTimer
	static stock FIX_SetTimer = 0;
	#define FIX_SetTimer                         (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="main">
 *     <problem>
 *         Gamemodes without this function give a console error.
 *     </problem>
 *     <solution>
 *         Make a stub version.
 *     </solution>
 *     <see>main</see>
 *     <author href="https://github.com/Y-Less" >Y_Less</author>
 * </fix>
 */

#if !defined FIX_main
	#define _FIXES_WARNING 121
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_main = _FIXES_DEFAULT;
	#define FIX_main                             _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_main)
	#undef FIX_main
	static stock FIX_main = 2;
	#define FIX_main                             (2)
#elseif FIX_main
	#undef FIX_main
	static stock FIX_main = 1;
	#define FIX_main                             (1)
#else
	#undef FIX_main
	static stock FIX_main = 0;
	#define FIX_main                             (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="Pawndoc">
 *     <problem>
 *         Pawndoc comments aren't ignored inside <c>#if</c> blocks, nor used
 *         on macros.  Plus are weird on <c>enum</c>s.
 *     </problem>
 *     <solution>
 *         Place fake functions or constants before the macros (depending on
 *         type) to attach to the documentation in the XML.  Plus a macro for
 *         going after enums to fix their weirdness, and one <c>CLOSE</c> macro
 *         to clean up an internal detail.
 *     </solution>
 *     <author href="https://github.com/Y-Less" >Y_Less</author>
 *     <post   href="https://github.com/pawn-lang/compiler/issues/674#issuecomment-908927779" />
 *     <see>HIDE_PAWNDOC</see>
 *     <see>FUNC_PAWNDOC</see>
 *     <see>CONST_PAWNDOC</see>
 *     <see>ENUM_PAWNDOC</see>
 *     <see>CLOSE_PAWNDOC</see>
 * </fix>
 */

#if !defined FIX_Pawndoc
	#define _FIXES_WARNING 122
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_Pawndoc = _FIXES_DEFAULT;
	#define FIX_Pawndoc                          _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_Pawndoc)
	#undef FIX_Pawndoc
	static stock FIX_Pawndoc = 2;
	#define FIX_Pawndoc                          (2)
#elseif FIX_Pawndoc
	#undef FIX_Pawndoc
	static stock FIX_Pawndoc = 1;
	#define FIX_Pawndoc                          (1)
#else
	#undef FIX_Pawndoc
	static stock FIX_Pawndoc = 0;
	#define FIX_Pawndoc                          (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="OnVehicleSpawn">
 *     <problem>
 *         Colour <c>-1</c> isn't synced.
 *     </problem>
 *     <solution>
 *         Manually control the colours.
 *     </solution>
 *     <see>FIXES_OnVehicleSpawn</see>
 *     <author href="https://github.com/Y-Less">Y_Less</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_OnVehicleSpawn
		#undef FIX_OnVehicleSpawn
	#endif
	static stock FIX_OnVehicleSpawn = 0;
	#define FIX_OnVehicleSpawn                   (0)
#elseif !defined FIX_OnVehicleSpawn
	#define _FIXES_WARNING 123
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_OnVehicleSpawn = _FIXES_DEFAULT;
	#define FIX_OnVehicleSpawn                   _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_OnVehicleSpawn)
	#undef FIX_OnVehicleSpawn
	static stock FIX_OnVehicleSpawn = 2;
	#define FIX_OnVehicleSpawn                   (2)
#elseif FIX_OnVehicleSpawn
	#undef FIX_OnVehicleSpawn
	static stock FIX_OnVehicleSpawn = 1;
	#define FIX_OnVehicleSpawn                   (1)
#else
	#undef FIX_OnVehicleSpawn
	static stock FIX_OnVehicleSpawn = 0;
	#define FIX_OnVehicleSpawn                   (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="floatfract">
 *     <problem>
 *         Incorrect on negative numbers.
 *     </problem>
 *     <solution>
 *         Use floatround and subtraction.
 *     </solution>
 *     <see>FIXES_floatfract</see>
 *     <author href="https://github.com/MuthaX">MuthaX</author>
 *     <post href="https://github.com/pawn-lang/sa-mp-fixes/issues/150" />
 * </fix>
 */

#if !defined FIX_floatfract
	#define _FIXES_WARNING 124
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_floatfract = _FIXES_DEFAULT;
	#define FIX_floatfract                       _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_floatfract)
	#undef FIX_floatfract
	static stock FIX_floatfract = 2;
	#define FIX_floatfract                       (2)
#elseif FIX_floatfract
	#undef FIX_floatfract
	static stock FIX_floatfract = 1;
	#define FIX_floatfract                       (1)
#else
	#undef FIX_floatfract
	static stock FIX_floatfract = 0;
	#define FIX_floatfract                       (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="strfind">
 *     <problem>
 *         The function is prone to OOB access when the search start index is
 *         negative.
 *     </problem>
 *     <solution>
 *         Clamp it to 0.
 *     </solution>
 *     <see>FIXES_strfind</see>
 *     <author href="https://github.com/Daniel-Cortez">Daniel-Cortez</author>
 *     <post href="https://github.com/pawn-lang/sa-mp-fixes/issues/91" />
 * </fix>
 */

#if !defined FIX_strfind
	#define _FIXES_WARNING 125
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_strfind = _FIXES_DEFAULT;
	#define FIX_strfind                          _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_strfind)
	#undef FIX_strfind
	static stock FIX_strfind = 2;
	#define FIX_strfind                          (2)
#elseif FIX_strfind
	#undef FIX_strfind
	static stock FIX_strfind = 1;
	#define FIX_strfind                          (1)
#else
	#undef FIX_strfind
	static stock FIX_strfind = 0;
	#define FIX_strfind                          (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="strdel">
 *     <problem>
 *         The function is prone to OOB access when the index of the first
 *         character to remove is negative.
 *     </problem>
 *     <solution>
 *         Clamp it to 0.
 *     </solution>
 *     <see>FIXES_strdel</see>
 *     <author href="https://github.com/Daniel-Cortez">Daniel-Cortez</author>
 *     <post href="https://github.com/pawn-lang/sa-mp-fixes/issues/91" />
 * </fix>
 */

#if !defined FIX_strdel
	#define _FIXES_WARNING 126
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_strdel = _FIXES_DEFAULT;
	#define FIX_strdel                           _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_strdel)
	#undef FIX_strdel
	static stock FIX_strdel = 2;
	#define FIX_strdel                           (2)
#elseif FIX_strdel
	#undef FIX_strdel
	static stock FIX_strdel = 1;
	#define FIX_strdel                           (1)
#else
	#undef FIX_strdel
	static stock FIX_strdel = 0;
	#define FIX_strdel                           (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="LocalNPCNatives">
 *     <problem>
 *         Many natives aren't defined in the NPC includes.  Simple ones can be
 *         defined in pawn.
 *     </problem>
 *     <solution>
 *         Write pawn reimplementations of natives that can be.
 *     </solution>
 *     <see>FIXES_CallLocalFunction</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 */

#if !_FIXES_NPC
	#if defined FIX_LocalNPCNatives
		#undef FIX_LocalNPCNatives
	#endif
	static stock FIX_LocalNPCNatives = 0;
	#define FIX_LocalNPCNatives                  (0)
#elseif !defined FIX_LocalNPCNatives
	#define _FIXES_WARNING 127
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_LocalNPCNatives = FIX_Natives;
	#define FIX_LocalNPCNatives                  FIX_Natives
#elseif _FIXES_IS_UNSET(FIX_LocalNPCNatives)
	#undef FIX_LocalNPCNatives
	static stock FIX_LocalNPCNatives = 2;
	#define FIX_LocalNPCNatives                  (2)
#elseif FIX_LocalNPCNatives
	#undef FIX_LocalNPCNatives
	static stock FIX_LocalNPCNatives = 1;
	#define FIX_LocalNPCNatives                  (1)
#else
	#undef FIX_LocalNPCNatives
	static stock FIX_LocalNPCNatives = 0;
	#define FIX_LocalNPCNatives                  (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="RemoteNPCNatives">
 *     <problem>
 *         Many natives aren't defined in the NPC includes.  Most need to be
 *         called in the GM remotely and the result returned.
 *     </problem>
 *     <solution>
 *         Call the natives remotely, where the return values aren't important.
 *     </solution>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 */

#if !defined FIX_RemoteNPCNatives
	#define _FIXES_WARNING 128
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_RemoteNPCNatives = FIX_Natives;
	#define FIX_RemoteNPCNatives                 FIX_Natives
#elseif _FIXES_IS_UNSET(FIX_RemoteNPCNatives)
	#undef FIX_RemoteNPCNatives
	static stock FIX_RemoteNPCNatives = 2;
	#define FIX_RemoteNPCNatives                 (2)
#elseif FIX_RemoteNPCNatives
	#undef FIX_RemoteNPCNatives
	static stock FIX_RemoteNPCNatives = 1;
	#define FIX_RemoteNPCNatives                 (1)
#else
	#undef FIX_RemoteNPCNatives
	static stock FIX_RemoteNPCNatives = 0;
	#define FIX_RemoteNPCNatives                 (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="deconst">
 *     <problem>
 *         Un-const-correct - uses <c>const</c> but shouldn't.
 *     </problem>
 *     <solution>
 *         Redefine it without, plus a <c>len</c> default.
 *     </solution>
 *     <see>FIXES_GetPlayerName</see>
 *     <see>FIXES_GetWeaponName</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 */

#if !defined FIX_deconst
	// Renamed the fix.
	#if defined FIX_GetPlayerName
		#if _FIXES_IS_UNSET(FIX_GetPlayerName)
			static stock FIX_deconst = 2;
			#define FIX_deconst                      (2)
		#else
			static stock FIX_deconst = FIX_GetPlayerName;
			#define FIX_deconst                      (FIX_GetPlayerName)
		#endif
	#else
		#define _FIXES_WARNING 129
		#tryinclude "_fixes_options"
		#undef _FIXES_WARNING
		static _FIXES_OPTION FIX_deconst = _FIXES_DEFAULT;
		#define FIX_deconst                      _FIXES_DEFAULT
	#endif
#elseif _FIXES_IS_UNSET(FIX_deconst)
	#undef FIX_deconst
	static stock FIX_deconst = 2;
	#define FIX_deconst                          (2)
#elseif FIX_deconst
	#undef FIX_deconst
	static stock FIX_deconst = 1;
	#define FIX_deconst                          (1)
#else
	#undef FIX_deconst
	static stock FIX_deconst = 0;
	#define FIX_deconst                          (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="Streamer_HasIntData">
 *     <problem>
 *         Int data functions expect more parameters than they specify.
 *     </problem>
 *     <solution>
 *         Pass a hidden fake one if the version is right.
 *     </solution>
 *     <see>FIXES_streamer</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 *     <post href="https://github.com/samp-incognito/samp-streamer-plugin/pull/380" />
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_Streamer_HasIntData
		#undef FIX_Streamer_HasIntData
	#endif
	static stock FIX_Streamer_HasIntData = 0;
	#define FIX_Streamer_HasIntData              (0)
#elseif !defined FIX_Streamer_HasIntData
	#define _FIXES_WARNING 130
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_Streamer_HasIntData = _FIXES_DEFAULT;
	#define FIX_Streamer_HasIntData              _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_Streamer_HasIntData)
	#undef FIX_Streamer_HasIntData
	static stock FIX_Streamer_HasIntData = 2;
	#define FIX_Streamer_HasIntData              (2)
#elseif FIX_Streamer_HasIntData
	#undef FIX_Streamer_HasIntData
	static stock FIX_Streamer_HasIntData = 1;
	#define FIX_Streamer_HasIntData              (1)
#else
	#undef FIX_Streamer_HasIntData
	static stock FIX_Streamer_HasIntData = 0;
	#define FIX_Streamer_HasIntData              (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="Streamer_RemoveIntData">
 *     <problem>
 *         Int data functions expect more parameters than they specify.
 *     </problem>
 *     <solution>
 *         Pass a hidden fake one if the version is right.
 *     </solution>
 *     <see>FIXES_streamer</see>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 *     <post href="https://github.com/samp-incognito/samp-streamer-plugin/pull/380" />
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_Streamer_RemoveIntData
		#undef FIX_Streamer_RemoveIntData
	#endif
	static stock FIX_Streamer_RemoveIntData = 0;
	#define FIX_Streamer_RemoveIntData           (0)
#elseif !defined FIX_Streamer_RemoveIntData
	#define _FIXES_WARNING 131
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_Streamer_RemoveIntData = _FIXES_DEFAULT;
	#define FIX_Streamer_RemoveIntData           _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_Streamer_RemoveIntData)
	#undef FIX_Streamer_RemoveIntData
	static stock FIX_Streamer_RemoveIntData = 2;
	#define FIX_Streamer_RemoveIntData           (2)
#elseif FIX_Streamer_RemoveIntData
	#undef FIX_Streamer_RemoveIntData
	static stock FIX_Streamer_RemoveIntData = 1;
	#define FIX_Streamer_RemoveIntData           (1)
#else
	#undef FIX_Streamer_RemoveIntData
	static stock FIX_Streamer_RemoveIntData = 0;
	#define FIX_Streamer_RemoveIntData           (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="defaults">
 *     <problem>
 *         Many functions are missing default values for string lengths.
 *     </problem>
 *     <solution>
 *         Add them.
 *     </solution>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 */

#if !defined FIX_defaults
	#define _FIXES_WARNING 132
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_defaults = _FIXES_DEFAULT;
	#define FIX_defaults                         _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_defaults)
	#undef FIX_defaults
	static stock FIX_defaults = 2;
	#define FIX_defaults                         (2)
#elseif FIX_defaults
	#undef FIX_defaults
	static stock FIX_defaults = 1;
	#define FIX_defaults                         (1)
#else
	#undef FIX_defaults
	static stock FIX_defaults = 0;
	#define FIX_defaults                         (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="limit_tags">
 *     <problem>
 *         Some limits, like `MAX_MENUS` are untagged, so can't be used properly.
 *     </problem>
 *     <solution>
 *         Redefine them with the tags added.
 *     </solution>
 *     <author    href="https://github.com/Y-Less/" >Y_Less</author>
 * </fix>
 */

#if !defined FIX_limit_tags
	#define _FIXES_WARNING 133
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_limit_tags = _FIXES_DEFAULT;
	#define FIX_limit_tags                       _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_limit_tags)
	#undef FIX_limit_tags
	static stock FIX_limit_tags = 2;
	#define FIX_limit_tags                       (2)
#elseif FIX_limit_tags
	#undef FIX_limit_tags
	static stock FIX_limit_tags = 1;
	#define FIX_limit_tags                       (1)
#else
	#undef FIX_limit_tags
	static stock FIX_limit_tags = 0;
	#define FIX_limit_tags                       (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="bool_tags">
 *     <problem>
 *         Many <c>true/false</c> parameters use <c>1/0</c> with no <c>bool:</c>
 *         tag.
 *     </problem>
 *     <solution>
 *         Add the tag.
 *     </solution>
 *     <author href="https://github.com/Y-Less/">Y_Less</author>
 * </fix>
 */

#if !defined FIX_bool_tags
	#define _FIXES_WARNING 134
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_bool_tags = _FIXES_DEFAULT;
	#define FIX_bool_tags                        _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_bool_tags)
	#undef FIX_bool_tags
	static stock FIX_bool_tags = 2;
	#define FIX_bool_tags                        (2)
#elseif FIX_bool_tags
	#undef FIX_bool_tags
	static stock FIX_bool_tags = 1;
	#define FIX_bool_tags                        (1)
#else
	#undef FIX_bool_tags
	static stock FIX_bool_tags = 0;
	#define FIX_bool_tags                        (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="TEXT_DRAW_ALIGN">
 *     <problem>
 *         The alignment modes for <c>TextDrawAlignment</c> are not defined by default.
 *     </problem>
 *     <solution>
 *         Define them.
 *     </solution>
 *     <author href="https://github.com/Y-Less/">Y_Less</author>
 * </fix>
 */

#if !defined FIX_TEXT_DRAW_ALIGN
	#if defined TEXT_DRAW_ALIGN_LEFT
		#if FIXES_EnableDeprecated
			#define _FIXES_WARNING 135
			#tryinclude "_fixes_options"
			#undef _FIXES_WARNING
			static _FIXES_OPTION FIX_TEXT_DRAW_ALIGN = FIXES_EnableDeprecated;
		#else
			_FIXES_CONST_PAWNDOC(FIX_TEXT_DRAW_ALIGN = FIXES_EnableDeprecated);
		#endif
		#define FIX_TEXT_DRAW_ALIGN              FIXES_EnableDeprecated
	#else
		#define _FIXES_WARNING 135
		#tryinclude "_fixes_options"
		#undef _FIXES_WARNING
		static _FIXES_OPTION FIX_TEXT_DRAW_ALIGN = _FIXES_DEFAULT;
		#define FIX_TEXT_DRAW_ALIGN              _FIXES_DEFAULT
	#endif
#elseif _FIXES_IS_UNSET(FIX_TEXT_DRAW_ALIGN)
	#undef FIX_TEXT_DRAW_ALIGN
	static stock FIX_TEXT_DRAW_ALIGN = 2;
	#define FIX_TEXT_DRAW_ALIGN                  (2)
#elseif FIX_TEXT_DRAW_ALIGN
	#undef FIX_TEXT_DRAW_ALIGN
	static stock FIX_TEXT_DRAW_ALIGN = 1;
	#define FIX_TEXT_DRAW_ALIGN                  (1)
#else
	#undef FIX_TEXT_DRAW_ALIGN
	static stock FIX_TEXT_DRAW_ALIGN = 0;
	#define FIX_TEXT_DRAW_ALIGN                  (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="TEXT_DRAW_FONT">
 *     <problem>
 *         The fonts for <c>TextDrawFont</c> are not defined by default.
 *     </problem>
 *     <solution>
 *         Define them.
 *     </solution>
 *     <author href="https://github.com/Y-Less/">Y_Less</author>
 * </fix>
 */

#if !defined FIX_TEXT_DRAW_FONT
	#if defined TEXT_DRAW_FONT_0
		#if FIXES_EnableDeprecated
			#define _FIXES_WARNING 136
			#tryinclude "_fixes_options"
			#undef _FIXES_WARNING
			static _FIXES_OPTION FIX_TEXT_DRAW_FONT = FIXES_EnableDeprecated;
		#else
			_FIXES_CONST_PAWNDOC(FIX_TEXT_DRAW_FONT = FIXES_EnableDeprecated);
		#endif
		#define FIX_TEXT_DRAW_FONT              FIXES_EnableDeprecated
	#else
		#define _FIXES_WARNING 136
		#tryinclude "_fixes_options"
		#undef _FIXES_WARNING
		static _FIXES_OPTION FIX_TEXT_DRAW_FONT = _FIXES_DEFAULT;
		#define FIX_TEXT_DRAW_FONT              _FIXES_DEFAULT
	#endif
#elseif _FIXES_IS_UNSET(FIX_TEXT_DRAW_FONT)
	#undef FIX_TEXT_DRAW_FONT
	static stock FIX_TEXT_DRAW_FONT = 2;
	#define FIX_TEXT_DRAW_FONT                  (2)
#elseif FIX_TEXT_DRAW_FONT
	#undef FIX_TEXT_DRAW_FONT
	static stock FIX_TEXT_DRAW_FONT = 1;
	#define FIX_TEXT_DRAW_FONT                  (1)
#else
	#undef FIX_TEXT_DRAW_FONT
	static stock FIX_TEXT_DRAW_FONT = 0;
	#define FIX_TEXT_DRAW_FONT                  (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="GetPlayerKeys">
 *     <problem>
 *         <c>GetPlayerKeys</c> and <c>OnPlayerKeyStateChange</c> don't actually
 *         deal with "keys", but "actions".  The defines don't correspond to
 *         real keyboard inputs, but bound game commands.  This is one of the
 *         biggest sources of confusion, even amongst intermediate coders.
 *     </problem>
 *     <solution>
 *         Rename the functions to use <c>Action</c> instead of <c>Key</c> and
 *         deprecate the old ones.
 *     </solution>
 *     <see>FIXES_GetPlayerActions</see>
 *     <see>OnPlayerControlsStateChange</see>
 *     <author href="https://github.com/Y-Less/">Y_Less</author>
 * </fix>
 */

#if !defined FIX_GetPlayerKeys
	#define _FIXES_WARNING 137
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_GetPlayerKeys = _FIXES_DEFAULT;
	#define FIX_GetPlayerKeys                    _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_GetPlayerKeys)
	#undef FIX_GetPlayerKeys
	static stock FIX_GetPlayerKeys = 2;
	#define FIX_GetPlayerKeys                    (2)
#elseif FIX_GetPlayerKeys
	#undef FIX_GetPlayerKeys
	static stock FIX_GetPlayerKeys = 1;
	#define FIX_GetPlayerKeys                    (1)
#else
	#undef FIX_GetPlayerKeys
	static stock FIX_GetPlayerKeys = 0;
	#define FIX_GetPlayerKeys                    (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="FORCE_SYNC">
 *     <problem>
 *         The sync modes for <c>ApplyAnimation</c> are not defined by default.
 *     </problem>
 *     <solution>
 *         Define them.
 *     </solution>
 *     <author href="https://github.com/Y-Less/">Y_Less</author>
 * </fix>
 */

#if !defined FIX_FORCE_SYNC
	#if defined SYNC_NONE
		#if FIXES_EnableDeprecated
			#define _FIXES_WARNING 138
			#tryinclude "_fixes_options"
			#undef _FIXES_WARNING
			static _FIXES_OPTION FIX_FORCE_SYNC = FIXES_EnableDeprecated;
		#else
			_FIXES_CONST_PAWNDOC(FIX_FORCE_SYNC = FIXES_EnableDeprecated);
		#endif
		#define FIX_FORCE_SYNC                   FIXES_EnableDeprecated
	#else
		#define _FIXES_WARNING 138
		#tryinclude "_fixes_options"
		#undef _FIXES_WARNING
		static _FIXES_OPTION FIX_FORCE_SYNC = _FIXES_DEFAULT;
		#define FIX_FORCE_SYNC                   _FIXES_DEFAULT
	#endif
#elseif _FIXES_IS_UNSET(FIX_FORCE_SYNC)
	#undef FIX_FORCE_SYNC
	static stock FIX_FORCE_SYNC = 2;
	#define FIX_FORCE_SYNC                       (2)
#elseif FIX_FORCE_SYNC
	#undef FIX_FORCE_SYNC
	static stock FIX_FORCE_SYNC = 1;
	#define FIX_FORCE_SYNC                       (1)
#else
	#undef FIX_FORCE_SYNC
	static stock FIX_FORCE_SYNC = 0;
	#define FIX_FORCE_SYNC                       (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="address_naught">
 *     <problem>
 *         When there are internal code errors that result in the wrong address
 *         being written to, more often than not that write clobbers whatever
 *         value is in address naught (<c>0x00000000</c>).
 *     </problem>
 *     <solution>
 *         While we can't stop all the bad address writes there are two things
 *         we can do.  Enable the anonymous automata, which is always at address
 *         naught, and never use it so that bad writes don't break something
 *         else, and enable address naught write detection in crashdetect.  Note
 *         that this will have to be disabled if you use the anonymous automata.
 *     </solution>
 *     <author href="https://github.com/Y-Less/">Y_Less</author>
 * </fix>
 */

#if !defined FIX_address_naught
	#define _FIXES_WARNING 139
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_address_naught = _FIXES_DEFAULT;
	#define FIX_address_naught                   _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_address_naught)
	#undef FIX_address_naught
	static stock FIX_address_naught = 2;
	#define FIX_address_naught                   (2)
#elseif FIX_address_naught
	#undef FIX_address_naught
	static stock FIX_address_naught = 1;
	#define FIX_address_naught                   (1)
#else
	#undef FIX_address_naught
	static stock FIX_address_naught = 0;
	#define FIX_address_naught                   (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="main2">
 *     <problem>
 *         <c>main</c> isn't called in filterscripts.
 *     </problem>
 *     <solution>
 *         Call it.
 *     </solution>
 *     <author href="https://github.com/Y-Less/">Y_Less</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_main2
		#undef FIX_main2
	#endif
	static stock FIX_main2 = 0;
	#define FIX_main2                            (0)
#elseif !defined FIX_main2
	#define _FIXES_WARNING 140
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_main2 = _FIXES_DEFAULT;
	#define FIX_main2                            _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_main2)
	#undef FIX_main2
	static stock FIX_main2 = 2;
	#define FIX_main2                            (2)
#elseif FIX_main2
	#undef FIX_main2
	static stock FIX_main2 = 1;
	#define FIX_main2                            (1)
#else
	#undef FIX_main2
	static stock FIX_main2 = 0;
	#define FIX_main2                            (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="npcmodes">
 *     <problem>
 *         There's no way to specify NPC modes in <c>server.cfg</c>.
 *     </problem>
 *     <solution>
 *         Read <c>npcmodes</c> from the file ONCE and load them automatically.
 *     </solution>
 *     <author href="https://github.com/Y-Less/">Y_Less</author>
 * </fix>
 */

#if _FIXES_NPC
	#if defined FIX_npcmodes
		#undef FIX_npcmodes
	#endif
	static stock FIX_npcmodes = 0;
	#define FIX_npcmodes                         (0)
#elseif !defined FIX_npcmodes
	#define _FIXES_WARNING 141
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_npcmodes = _FIXES_DEFAULT;
	#define FIX_npcmodes                         _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_npcmodes)
	#undef FIX_npcmodes
	static stock FIX_npcmodes = 2;
	#define FIX_npcmodes                         (2)
#elseif FIX_npcmodes
	#undef FIX_npcmodes
	static stock FIX_npcmodes = 1;
	#define FIX_npcmodes                         (1)
#else
	#undef FIX_npcmodes
	static stock FIX_npcmodes = 0;
	#define FIX_npcmodes                         (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="fgetchar2">
 *     <problem>
 *         Has an extra <c>value</c> parameter.
 *     </problem>
 *     <solution>
 *         Remove it.
 *     </solution>
 *     <see>FIXES_fgetchar</see>
 *     <author href="https://github.com/Y-Less/">Y_Less</author>
 * </fix>
 */

#if !defined FIX_fgetchar2
	#define _FIXES_WARNING 142
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_fgetchar2 = _FIXES_DEFAULT;
	#define FIX_fgetchar2                        _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_fgetchar2)
	#undef FIX_fgetchar2
	static stock FIX_fgetchar2 = 2;
	#define FIX_fgetchar2                        (2)
#elseif FIX_fgetchar2
	#undef FIX_fgetchar2
	static stock FIX_fgetchar2 = 1;
	#define FIX_fgetchar2                        (1)
#else
	#undef FIX_fgetchar2
	static stock FIX_fgetchar2 = 0;
	#define FIX_fgetchar2                        (0)
#endif

/**
 * <library>fixes.inc</library>
 * <fix name="memcpy">
 *     <problem>
 *         The <c>index</c> is meant to be an index in to <c>source</c> (in
 *         bytes) for where to read the data from; however, it is treated as an
 *         index (in bytes) for where to write the data to in <c>dest</c>.
 *     </problem>
 *     <solution>
 *         Copy two cells with an offset to a temporary buffer, copy the rest of
 *         the data to the next cell in the destination, then save the high cell
 *         of the temporary storage.
 *     </solution>
 *     <see>FIXES_memcpy</see>
 *     <author href="https://github.com/Y-Less/">Y_Less</author>
 * </fix>
 */

#if !defined FIX_memcpy
	#define _FIXES_WARNING 143
	#tryinclude "_fixes_options"
	#undef _FIXES_WARNING
	static _FIXES_OPTION FIX_memcpy = _FIXES_DEFAULT;
	#define FIX_memcpy                           _FIXES_DEFAULT
#elseif _FIXES_IS_UNSET(FIX_memcpy)
	#undef FIX_memcpy
	static stock FIX_memcpy = 2;
	#define FIX_memcpy                           (2)
#elseif FIX_memcpy
	#undef FIX_memcpy
	static stock FIX_memcpy = 1;
	#define FIX_memcpy                           (1)
#else
	#undef FIX_memcpy
	static stock FIX_memcpy = 0;
	#define FIX_memcpy                           (0)
#endif

/*

    88b           d88
    888b         d888
    88`8b       d8'88
    88 `8b     d8' 88  ,adPPYYba,   ,adPPYba,  8b,dPPYba,   ,adPPYba,   ,adPPYba,
    88  `8b   d8'  88  ""     `Y8  a8"     ""  88P'   "Y8  a8"     "8a  I8[    ""
    88   `8b d8'   88  ,adPPPPP88  8b          88          8b       d8   `"Y8ba,
    88    `888'    88  88,    ,88  "8a,   ,aa  88          "8a,   ,a8"  aa    ]8I
    88     `8'     88  `"8bbdP"Y8   `"Ybbd8"'  88           `"YbbdP"'   `"YbbdP"'



*/

// Generic check to see if ANY menu fix is enabled.  Used to simplify tests.
#if FIX_Menus || FIX_AddMenuItem || FIX_SetMenuColumnHeader || FIX_ShowMenuForPlayer || FIX_HideMenuForPlayer || FIX_DisableMenu || FIX_DisableMenuRow
	#define _FIX_Menus                           (1)
#else
	#define _FIX_Menus                           (0)
#endif

// Creates a `const` var using a descriptive syntax.  See:
// https://github.com/pawn-lang/compiler/issues/674#issuecomment-908927779
#if FIX_Pawndoc
	#define HIDE_PAWNDOC _FIXES_HIDE_PAWNDOC
#endif

#if FIX_Pawndoc
	#define FUNC_PAWNDOC _FIXES_FUNC_PAWNDOC
	#define FUNCTION_PAWNDOC _FIXES_FUNC_PAWNDOC
#endif

#if FIX_Pawndoc
	#define CONST_PAWNDOC _FIXES_CONST_PAWNDOC
#endif

#if FIX_Pawndoc
	#define ENUM_PAWNDOC _FIXES_ENUM_PAWNDOC
#endif

/**
 * <library>fixes.inc</library>
 * <remarks>
 * Mark all natives as const-correct in an a_samp-compatible way.
 * </remarks>
 */

// Just in case the define already exists, don't break the documentation.
#if defined SAMP_CONST_CORRECT
	#undef SAMP_CONST_CORRECT
	_FIXES_CONST_PAWNDOC(SAMP_CONST_CORRECT = 1);
	#define SAMP_CONST_CORRECT
#else
	_FIXES_CONST_PAWNDOC(SAMP_CONST_CORRECT = 1);
#endif

// And redefine it either way.
#if FIX_const
	#define SAMP_CONST_CORRECT
#endif

/**
 * <library>fixes.inc</library>
 * <remarks>
 * Breaks <c>#pragma tabsize 0</c> in such a way that the compiler gives the
 * following error:
 *
 * <code>
 *     error 017: undefined symbol "do_not_use_tabsize_0"
 * </code>
 *
 * There is ZERO reason to use it.  There are ocassionally times when an
 * indentation reset is required, usually because of macros containing code that
 * would otherwise appear correct.  For example:
 *
 * <code>
 *     #define TEST_MACRO                                                       <br />
 *                                                                              <br />
 *     main()                                                                   <br />
 *     {                                                                        <br /><indent />
 *         new a = 42;                                                          <br /><indent />
 *         if (a)                                                               <br /><indent />
 *         {                                                                    <br /><indent /><indent />
 *             print("true");                                                   <br /><indent />
 *         }                                                                    <br /><indent />
 *         #if defined TEST_MACRO                                               <br /><indent /><indent />
 *             else                                                             <br /><indent /><indent />
 *             {                                                                <br /><indent /><indent /><indent />
 *                 print("false");                                              <br /><indent /><indent />
 *             }                                                                <br /><indent /><indent />
 *             a = 42;                                                          <br /><indent />
 *         #endif                                                               <br /><indent />
 *         printf("a = %d", a);                                                 <br />
 *     }
 * </code>
 *
 * Even that can be fixed without <c>tabsize 0</c>, simply by restating the
 * correct indentation level, which resets the internal depth tracking:
 *
 * <code>
 *     #define TEST_MACRO                                                       <br />
 *                                                                              <br />
 *     main()                                                                   <br />
 *     {                                                                        <br /><indent />
 *         new a = 42;                                                          <br /><indent />
 *         if (a)                                                               <br /><indent />
 *         {                                                                    <br /><indent /><indent />
 *             print("true");                                                   <br /><indent />
 *         }                                                                    <br /><indent />
 *         #if defined TEST_MACRO                                               <br /><indent /><indent />
 *             else                                                             <br /><indent /><indent />
 *             {                                                                <br /><indent /><indent /><indent />
 *                 print("false");                                              <br /><indent /><indent />
 *             }                                                                <br /><indent /><indent />
 *             #pragma tabsize 4                                                <br /><indent /><indent />
 *             a = 42;                                                          <br /><indent />
 *         #endif                                                               <br /><indent />
 *         printf("a = %d", a);                                                 <br />
 *     }
 * </code>
 *
 * There is just no excuse.
 * </remarks>
 */

_FIXES_CONST_PAWNDOC(do_not_use_tabsize_0 = cellmin);
#if FIX_tabsize
	#define tabsize%00%0\10;%0 _DUMMY_do_not_use_tabsize_0
#endif

/**
 * <library>fixes.inc</library>
 * <remarks>
 * fixes.inc exists
 * </remarks>
 */

_FIXES_CONST_PAWNDOC(FIXES_EXISTS = 1);
#define FIXES_EXISTS

/**
 * <library>fixes.inc</library>
 * <remarks>
 * The include is fully const-correct (and backwards-compatible).
 * </remarks>
 */

_FIXES_CONST_PAWNDOC(FIXES_CONST_CORRECT = 1);
#define FIXES_CONST_CORRECT

/**
 * <library>fixes.inc</library>
 * <remarks>
 * The include is fully tag-correct (and backwards-compatible), i.e. optionally
 * uses additional tags in callbacks such as `OnPlayerStateChange`.
 * </remarks>
 */

_FIXES_CONST_PAWNDOC(FIXES_TAG_CORRECT = 1);
#define FIXES_TAG_CORRECT

/**
 * <library>fixes.inc</library>
 * <remarks>
 * The include has methods of hiding unwanted pawndoc declarations.
 * </remarks>
 */

_FIXES_CONST_PAWNDOC(FIXES_PAWNDOC = 1);
#define FIXES_PAWNDOC

/**
 * <library>fixes.inc</library>
 * <remarks>
 * The include defines the pubic variable `@_`, which is a unique ID for the
 * current script.  This is also defined by YSI if it isn't defined here.
 * </remarks>
 */

_FIXES_CONST_PAWNDOC(FIXES_ID = 1);
#define FIXES_ID

/**
 * <library>fixes.inc</library>
 * <remarks>
 * The additional API functions (see above) were defined and can be used.
 * (<c>#if defined FIXES_API</c>).
 * </remarks>
 */

_FIXES_CONST_PAWNDOC(FIXES_API = 1);
#if FIX_API
	#define FIXES_API
#endif

/**
 * <library>fixes.inc</library>
 * <remarks>
 * fixes.inc uses advanced state-based ALS hooks, not just regular ones.
 * </remarks>
 */

#if FIXES_NoYSI
	_FIXES_HIDE_PAWNDOC(FIXES_USES_STATE_HOOKS_);
#else
	_FIXES_CONST_PAWNDOC(FIXES_USES_STATE_HOOKS = 1);
	#define FIXES_UseStateHooks
	#define FIXES_USES_STATE_HOOKS
#endif

/**
 * <library>fixes.inc</library>
 * <remarks>
 * A special "printf" function only compiled when "FIXES_Debug" is set.
 * </remarks>
 */

_FIXES_FUNC_PAWNDOC(FIXES_PRINTF(const str[], ...));
#define _FIXES_PRINTF(%0); print(_FIXES_gIsFilterscript ? FIXES_gscPrintFFS : FIXES_gscPrintFGM),printf("*** " %0);

/**
 * <library>fixes.inc</library>
 * <remarks>
 * Test to see if this script is in command or not (master).
 * </remarks>
 */

_FIXES_FUNC_PAWNDOC(bool:_FIXES_IS_IN_CHARGE());
#if FIXES_Single
	#define _FIXES_IS_IN_CHARGE(%0)
#else
	#define _FIXES_IS_IN_CHARGE(%0) if (%0(FIXES_gsSettings & e_FIXES_SETTINGS_IN_CHARGE))
#endif

/**
 * <library>fixes.inc</library>
 * <remarks>
 * Set a variable, which may be a property or an array, depending on compile-
 * time options.
 * </remarks>
 */

_FIXES_FUNC_PAWNDOC(FIXES_SET(const var[], playerid, value));
#if FIXES_Single
	#define FIXES_SET(%0,%1,%2) (FIXES_gs%0[(%1)] = (%2))
#else
	#define FIXES_SET(%0,%1,%2) SetPVarInt__((%1), FIXES_pvar%0, _:(%2))
#endif

/**
 * <library>fixes.inc</library>
 * <remarks>
 * Get a variable, which may be a property or an array, depending on compile-
 * time options.
 * </remarks>
 */

_FIXES_FUNC_PAWNDOC(FIXES_GET(const var[], playerid));
#if FIXES_Single
	#define FIXES_GET(%0,%1) (FIXES_gs%0[(%1)])
#else
	#define FIXES_GET(%0,%1) GetPVarInt__((%1), FIXES_pvar%0)
#endif

/**
 * <library>fixes.inc</library>
 * <remarks>
 * Pretty standard.
 * </remarks>
 */

_FIXES_FUNC_PAWNDOC(bool:_FIXES_IS_NULL(const string[]));
#define _FIXES_IS_NULL(%0) ((%0[(%0[0])=='\1'])=='\0')

/**
 * <library>fixes.inc</library>
 * <remarks>
 * Do a ceiling division of the first number by the second number.
 * </remarks>
 */

_FIXES_FUNC_PAWNDOC(_FIXES_CEILDIV(a, b));
#define _FIXES_CEILDIV(%0,%1) (((%0) + (%1) - 1) / (%1))

/**
 * <library>fixes.inc</library>
 * <remarks>
 * A new version of "foreach", but just for this library.
 * </remarks>
 */

_FIXES_FUNC_PAWNDOC(_FIXES_FOREACH(iterator[], &playerid));
#define _FIXES_FOREACH(%1,%0) for (new %0 = MAX_PLAYERS; (%0 = %1[%0]) != MAX_PLAYERS; )

/**
 * <library>fixes.inc</library>
 * <remarks>
 * Checks if the first parameter is between the other two: %1 &lt;= %0 &lt;%2 (but
 * faster).
 * </remarks>
 */

_FIXES_FUNC_PAWNDOC(bool:_FIXES_IN_RANGE(min, value, max));
#define _FIXES_IN_RANGE(%0,%1,%2) ((_:(%0) - (_:(%1) + cellmin)) < (_:(%2) - (_:(%1) + cellmin)))

/**
 * <library>fixes.inc</library>
 * <remarks>
 * Checks if the first parameter is not between the other two:
 * <c>!(%1 &lt;= %0 &lt; %2)</c>(but faster).
 * </remarks>
 */

_FIXES_FUNC_PAWNDOC(bool:_FIXES_NO_RANGE(min, value, max));
#define _FIXES_NO_RANGE(%0,%1,%2) (((%0) - ((%1) + cellmin)) >= ((%2) - ((%1) + cellmin)))

/**
 * <library>fixes.inc</library>
 * <remarks>
 * Forwards a hooked callbacks, and defines the default state implementations.
 * </remarks>
 */

_FIXES_FUNC_PAWNDOC(_FIXES_FORWARD(const function[], ...));
#if !FIXES_NoYSI
	#define _FIXES_FORWARD%0(%1); \
		forward%0(%1);                                                          \
		public%0(%1) <_ALS : _ALS_x0, _ALS : _ALS_x1> { return 1; }             \
		public%0(%1) <> { return 1; }
#endif

/**
 * <library>fixes.inc</library>
 * <remarks>
 * Check if the ID is in range of player IDs.
 * </remarks>
 */

_FIXES_FUNC_PAWNDOC(bool:_FIXES_IS_VALID_PLAYER(playerid));
#define _FIXES_IS_VALID_PLAYER(%0) _FIXES_IN_RANGE((%0), 0, MAX_PLAYERS)

/**
 * <library>fixes.inc</library>
 * <remarks>
 * Always valid <c>IsPlayerConnected</c> check.
 * </remarks>
 */

_FIXES_FUNC_PAWNDOC(bool:_FIXES_IS_PLAYER_CONNECTED(playerid));
#define _FIXES_IS_PLAYER_CONNECTED(%0) (_FIXES_IS_VALID_PLAYER(%0) && IsPlayerConnected__(%0))

/**
 * <library>fixes.inc</library>
 * <remarks>
 * Either <c>const</c> or <c>static stock const</c> depending on the value of
 * <c>FIXES_Debug</c>, so we can examine them externally.
 * </remarks>
 */

_FIXES_CONST_PAWNDOC(_FIXES_STATIC_STOCK_CONST = cellmin);
#if FIXES_Debug
	#define _FIXES_STATIC_STOCK_CONST const
#else
	#define _FIXES_STATIC_STOCK_CONST static stock const
#endif

/**
 * <library>fixes.inc</library>
 * <remarks>
 * Either <c>new</c> or <c>static stock</c> depending on the value of
 * <c>FIXES_Debug</c>, so we can examine them externally.
 * </remarks>
 */

_FIXES_CONST_PAWNDOC(_FIXES_STATIC_STOCK = cellmin);
#if FIXES_Debug
	#define _FIXES_STATIC_STOCK new
#else
	#define _FIXES_STATIC_STOCK static stock
#endif

/**
 * <library>fixes.inc</library>
 * <remarks>
 * Either <c>const</c> or nothing, depending on the value of <c>FIX_const</c>,
 * so we can add <c>const</c> as required on the new compiler.
 * </remarks>
 */

_FIXES_CONST_PAWNDOC(_FIXES_MAYBE_CONST = cellmin);
#if FIX_const
	#define _FIXES_MAYBE_CONST const
#else
	#define _FIXES_MAYBE_CONST
#endif

/**
 * <library>fixes.inc</library>
 * <remarks>
 * Convert a non-zero value to <c>true</c>, and <c>0</c> to <c>false</c> when
 * <c>FIX_bool_tags</c> is off.  Otherwise do nothing.
 * </remarks>
 */

_FIXES_FUNC_PAWNDOC(_FIXES_TO_BOOL(value));
#if FIX_bool_tags
	#define _FIXES_TO_BOOL(%0) ((%0))
#else
	#define _FIXES_TO_BOOL(%0) (!!(%0))
#endif

/**
 * <library>fixes.inc</library>
 * <remarks>
 * Either <c>bool</c> or <c>_</c>, depending on the value of
 * <c>FIX_bool_tags</c>, to reduce excessive warnings.
 * </remarks>
 */

_FIXES_CONST_PAWNDOC(_FIXES_MAYBE_BOOL = cellmin);
#if FIX_bool_tags
	#define _FIXES_MAYBE_BOOL bool
#else
	#define _FIXES_MAYBE_BOOL _
#endif

/**
 * <library>fixes.inc</library>
 * <remarks>
 * Either <c>true</c> or <c>1</c>, depending on the value of
 * <c>FIX_bool_tags</c>, to reduce excessive warnings.
 * </remarks>
 */

_FIXES_CONST_PAWNDOC(_FIXES_MAYBE_TRUE = 1);
#if FIX_bool_tags
	#define _FIXES_MAYBE_TRUE true
#else
	#define _FIXES_MAYBE_TRUE 1
#endif

/**
 * <library>fixes.inc</library>
 * <remarks>
 * Either <c>false</c> or <c>0</c>, depending on the value of
 * <c>FIX_bool_tags</c>, to reduce excessive warnings.
 * </remarks>
 */

_FIXES_CONST_PAWNDOC(_FIXES_MAYBE_FALSE = 0);
#if FIX_bool_tags
	#define _FIXES_MAYBE_FALSE false
#else
	#define _FIXES_MAYBE_FALSE 0
#endif

/**
 * <library>fixes.inc</library>
 * <remarks>
 * The number of bytes in a cell.
 * </remarks>
 */

_FIXES_CONST_PAWNDOC(_FIXES_CELLBYTES = cellbits / charbits);
#define _FIXES_CELLBYTES (cellbits / charbits)

/**
 * <library>fixes.inc</library>
 * <remarks>
 * A test to see if <c>#pragma pack 1</c> is enabled.
 * </remarks>
 */

static stock const _FIXES_PACKED_TEST[] = " ";

#if sizeof (_FIXES_PACKED_TEST) == 1
	#define _FIXES_STRING_PACKING (1)
	#define _FIXES_PACK
	#define _FIXES_UNPACK !
#else
	#define _FIXES_STRING_PACKING (0)
	#define _FIXES_PACK !
	#define _FIXES_UNPACK
#endif

/*

    88888888ba,                   ad88  88               88           88
    88      `"8b                 d8"    ""               ""    ,d     ""
    88        `8b                88                            88
    88         88   ,adPPYba,  MM88MMM  88  8b,dPPYba,   88  MM88MMM  88   ,adPPYba,   8b,dPPYba,   ,adPPYba,
    88         88  a8P_____88    88     88  88P'   `"8a  88    88     88  a8"     "8a  88P'   `"8a  I8[    ""
    88         8P  8PP"""""""    88     88  88       88  88    88     88  8b       d8  88       88   `"Y8ba,
    88      .a8P   "8b,   ,aa    88     88  88       88  88    88,    88  "8a,   ,a8"  88       88  aa    ]8I
    88888888Y"'     `"Ybbd8"'    88     88  88       88  88    "Y888  88   `"YbbdP"'   88       88  `"YbbdP"'



*/

/**
 * <library>fixes.inc</library>
 * <remarks>
 * SA:MP limit with the correct tag added.
 * </remarks>
 */

#if !defined MAX_TEXT_DRAWS
	#define MAX_TEXT_DRAWS (2048)
#endif
const Text:MAX_TEXT_DRAWS__ = Text:MAX_TEXT_DRAWS;

/**
 * <library>fixes.inc</library>
 * <remarks>
 * SA:MP limit with the correct tag added.
 * </remarks>
 */

#if defined FIX_limit_tags
	#undef MAX_TEXT_DRAWS
	_FIXES_CONST_PAWNDOC(MAX_TEXT_DRAWS = MAX_TEXT_DRAWS__);
	#define MAX_TEXT_DRAWS MAX_TEXT_DRAWS__
#else
	_FIXES_HIDE_PAWNDOC(MAX_TEXT_DRAWS);
#endif

/**
 * <library>fixes.inc</library>
 * <remarks>
 * SA:MP limit with the correct tag added.
 * </remarks>
 */

#if !defined MAX_PLAYER_TEXT_DRAWS
	#define MAX_PLAYER_TEXT_DRAWS (256)
#endif
const PlayerText:MAX_PLAYER_TEXT_DRAWS__ = PlayerText:MAX_PLAYER_TEXT_DRAWS;

/**
 * <library>fixes.inc</library>
 * <remarks>
 * SA:MP limit with the correct tag added.
 * </remarks>
 */

#if defined FIX_limit_tags
	#undef MAX_PLAYER_TEXT_DRAWS
	_FIXES_CONST_PAWNDOC(MAX_PLAYER_TEXT_DRAWS = MAX_PLAYER_TEXT_DRAWS__);
	#define MAX_PLAYER_TEXT_DRAWS MAX_PLAYER_TEXT_DRAWS__
#else
	_FIXES_HIDE_PAWNDOC(MAX_PLAYER_TEXT_DRAWS);
#endif

/**
 * <library>fixes.inc</library>
 * <remarks>
 * SA:MP limit with the correct tag added.
 * </remarks>
 */

#if !defined MAX_MENUS
	#define MAX_MENUS (128)
#endif
const Menu:MAX_MENUS__ = Menu:MAX_MENUS;

/**
 * <library>fixes.inc</library>
 * <remarks>
 * SA:MP limit with the correct tag added.
 * </remarks>
 */

#if defined FIX_limit_tags
	#undef MAX_MENUS
	_FIXES_CONST_PAWNDOC(MAX_MENUS = MAX_MENUS__);
	#define MAX_MENUS MAX_MENUS__
#else
	_FIXES_HIDE_PAWNDOC(MAX_MENUS);
#endif

/**
 * <library>fixes.inc</library>
 * <remarks>
 * SA:MP limit with the correct tag added.
 * </remarks>
 */

#if !defined MAX_3DTEXT_GLOBAL
	#define MAX_3DTEXT_GLOBAL (1024)
#endif
const Text3D:MAX_3DTEXT_GLOBAL__ = Text3D:MAX_3DTEXT_GLOBAL;

/**
 * <library>fixes.inc</library>
 * <remarks>
 * SA:MP limit with the correct tag added.
 * </remarks>
 */

#if defined FIX_limit_tags
	#undef MAX_3DTEXT_GLOBAL
	_FIXES_CONST_PAWNDOC(MAX_3DTEXT_GLOBAL = MAX_3DTEXT_GLOBAL__);
	#define MAX_3DTEXT_GLOBAL MAX_3DTEXT_GLOBAL__
#else
	_FIXES_HIDE_PAWNDOC(MAX_3DTEXT_GLOBAL);
#endif

/**
 * <library>fixes.inc</library>
 * <remarks>
 * SA:MP limit with the correct tag added.
 * </remarks>
 */

#if !defined MAX_3DTEXT_PLAYER
	#define MAX_3DTEXT_PLAYER (1024)
#endif
const PlayerText3D:MAX_3DTEXT_PLAYER__ = PlayerText3D:MAX_3DTEXT_PLAYER;

/**
 * <library>fixes.inc</library>
 * <remarks>
 * SA:MP limit with the correct tag added.
 * </remarks>
 */

#if defined FIX_limit_tags
	#undef MAX_3DTEXT_PLAYER
	_FIXES_CONST_PAWNDOC(MAX_3DTEXT_PLAYER = MAX_3DTEXT_PLAYER__);
	#define MAX_3DTEXT_PLAYER MAX_3DTEXT_PLAYER__
#else
	_FIXES_HIDE_PAWNDOC(MAX_3DTEXT_PLAYER);
#endif

/**
 * <library>fixes.inc</library>
 * <remarks>
 * SA:MP limit with the correct tag added.
 * </remarks>
 */

#if !defined INVALID_PLAYER_TEXT_DRAW
	#if defined INVALID_TEXT_DRAW
		#define INVALID_PLAYER_TEXT_DRAW INVALID_TEXT_DRAW
	#else
		#define INVALID_PLAYER_TEXT_DRAW (0xFFFF)
	#endif
#endif

const PlayerText:INVALID_PLAYER_TEXT_DRAW__ = PlayerText:INVALID_PLAYER_TEXT_DRAW;

/**
 * <library>fixes.inc</library>
 * <remarks>
 * SA:MP limit with the correct tag added.
 * </remarks>
 */

#if defined FIX_limit_tags
	#undef INVALID_PLAYER_TEXT_DRAW
	_FIXES_CONST_PAWNDOC(INVALID_PLAYER_TEXT_DRAW = INVALID_PLAYER_TEXT_DRAW__);
	#define INVALID_PLAYER_TEXT_DRAW INVALID_PLAYER_TEXT_DRAW__
#else
	_FIXES_HIDE_PAWNDOC(INVALID_PLAYER_TEXT_DRAW);
#endif

/**
 * <library>fixes.inc</library>
 * <remarks>
 * SA:MP limit with the correct tag added.
 * </remarks>
 */

#if !defined INVALID_PLAYER_3DTEXT_ID
	#if defined INVALID_3DTEXT_ID
		#define INVALID_PLAYER_3DTEXT_ID INVALID_3DTEXT_ID
	#else
		#define INVALID_PLAYER_3DTEXT_ID (0xFFFF)
	#endif
#endif
const PlayerText3D:INVALID_PLAYER_3DTEXT_ID__ = PlayerText3D:INVALID_PLAYER_3DTEXT_ID;

/**
 * <library>fixes.inc</library>
 * <remarks>
 * SA:MP limit with the correct tag added.
 * </remarks>
 */

#if defined FIX_limit_tags
	#undef INVALID_PLAYER_3DTEXT_ID
	_FIXES_CONST_PAWNDOC(INVALID_PLAYER_3DTEXT_ID = INVALID_PLAYER_3DTEXT_ID__);
	#define INVALID_PLAYER_3DTEXT_ID INVALID_PLAYER_3DTEXT_ID__
#else
	_FIXES_HIDE_PAWNDOC(INVALID_PLAYER_3DTEXT_ID);
#endif

/**
 * <library>fixes.inc</library>
 * <remarks>
 * SA:MP limit with the correct tag added.
 * </remarks>
 */

#if !defined INVALID_3DTEXT_ID
	#define INVALID_3DTEXT_ID (0xFFFF)
#endif
const Text3D:INVALID_3DTEXT_ID__ = Text3D:INVALID_3DTEXT_ID;

/**
 * <library>fixes.inc</library>
 * <remarks>
 * SA:MP limit with the correct tag added.
 * </remarks>
 */

#if defined FIX_limit_tags
	#undef INVALID_3DTEXT_ID
	_FIXES_CONST_PAWNDOC(INVALID_3DTEXT_ID = INVALID_3DTEXT_ID__);
	#define INVALID_3DTEXT_ID INVALID_3DTEXT_ID__
#else
	_FIXES_HIDE_PAWNDOC(INVALID_3DTEXT_ID);
#endif

/**
 * <library>fixes.inc</library>
 * <remarks>
 * SA:MP limit with the correct tag added.
 * </remarks>
 */

#if !defined INVALID_MENU
	#define INVALID_MENU (0xFF)
#endif
const Menu:INVALID_MENU__ = Menu:INVALID_MENU;

/**
 * <library>fixes.inc</library>
 * <remarks>
 * SA:MP limit with the correct tag added.
 * </remarks>
 */

#if defined FIX_limit_tags
	#undef INVALID_MENU
	_FIXES_CONST_PAWNDOC(INVALID_MENU = INVALID_MENU__);
	#define INVALID_MENU INVALID_MENU__
#else
	_FIXES_HIDE_PAWNDOC(INVALID_MENU);
#endif

/**
 * <library>fixes.inc</library>
 * <remarks>
 * SA:MP limit with the correct tag added.
 * </remarks>
 */

#if !defined INVALID_TEXT_DRAW
	#define INVALID_TEXT_DRAW (0xFFFF)
#endif
const Text:INVALID_TEXT_DRAW__ = Text:INVALID_TEXT_DRAW;

/**
 * <library>fixes.inc</library>
 * <remarks>
 * SA:MP limit with the correct tag added.
 * </remarks>
 */

#if defined FIX_limit_tags
	#undef INVALID_TEXT_DRAW
	_FIXES_CONST_PAWNDOC(INVALID_TEXT_DRAW = INVALID_TEXT_DRAW__);
	#define INVALID_TEXT_DRAW INVALID_TEXT_DRAW__
#else
	_FIXES_HIDE_PAWNDOC(INVALID_TEXT_DRAW);
#endif

/**
 * <library>fixes.inc</library>
 * <remarks>
 * Future-compatible tag definitions.  <c>CONTROLS:</c> is defined as <c>_:</c>
 * when enhanced tags are disabled, and <c>E_KEY:</c> when they are enabled.
 * </remarks>
 */

#if defined CONTROLS
	_FIXES_HIDE_PAWNDOC(FIXES_CONTROLS_);
#elseif FIX_GetPlayerKeys
	_FIXES_CONST_PAWNDOC(CONTROLS = cellmin);
	#if defined __TAG
		#define CONTROLS: __TAG(CONTROLS):
	#else
		#define CONTROLS: _:
	#endif
#else
	#define CONTROLS: KEY:
#endif

/**
 * <library>fixes.inc</library>
 * <remarks>
 * Old <c>KEY:</c> tags for <c>GetPlayerKeys</c>, without the rename.
 * </remarks>
 */

#if defined KEY
	_FIXES_HIDE_PAWNDOC(FIXES_KEY_);
#else
	_FIXES_CONST_PAWNDOC(KEY = cellmin);
	#if defined __TAG
		#define KEY: __TAG(KEY):
	#else
		#define KEY: _:
	#endif
#endif

/**
 * <library>fixes.inc</library>
 * <remarks>
 * Future-compatible tag definitions.  <c>VEHICLE_PARAMS:</c> is defined as
 * <c>_:</c> when enhanced tags are disabled, and <c>E_VEHICLE_PARAMS:</c> when
 * they are enabled.
 * </remarks>
 */

#if defined VEHICLE_PARAMS
	_FIXES_HIDE_PAWNDOC(FIXES_VEHICLE_PARAMS_);
#else
	_FIXES_CONST_PAWNDOC(VEHICLE_PARAMS = cellmin);
	#if defined __TAG
		#define VEHICLE_PARAMS: __TAG(VEHICLE_PARAMS):
	#else
		#define VEHICLE_PARAMS: _:
	#endif
#endif

/**
 * <library>fixes.inc</library>
 * <remarks>
 * Future-compatible tag definitions.  <c>PLAYER_STATE:</c> is defined as
 * <c>_:</c> when enhanced tags are disabled, and <c>E_PLAYER_STATE:</c> when
 * they are enabled.
 * </remarks>
 */

#if defined PLAYER_STATE
	_FIXES_HIDE_PAWNDOC(FIXES_PLAYER_STATE_);
#else
	_FIXES_CONST_PAWNDOC(PLAYER_STATE = cellmin);
	#if defined __TAG
		#define PLAYER_STATE: __TAG(PLAYER_STATE):
	#else
		#define PLAYER_STATE: _:
	#endif
#endif

/**
 * <library>fixes.inc</library>
 * <remarks>
 * Future-compatible tag definitions.  <c>SPECIAL_ACTION:</c> is defined as
 * <c>_:</c> when enhanced tags are disabled, and <c>E_SPECIAL_ACTION:</c> when
 * they are enabled.
 * </remarks>
 */

#if defined SPECIAL_ACTION
	_FIXES_HIDE_PAWNDOC(FIXES_SPECIAL_ACTION_);
#else
	_FIXES_CONST_PAWNDOC(SPECIAL_ACTION = cellmin);
	#if defined __TAG
		#define SPECIAL_ACTION: __TAG(SPECIAL_ACTION):
	#else
		#define SPECIAL_ACTION: _:
	#endif
#endif

/**
 * <library>fixes.inc</library>
 * <remarks>
 * Future-compatible tag definitions.  <c>PLAYER_VARTYPE:</c> is defined as
 * <c>_:</c> when enhanced tags are disabled, and <c>E_PLAYER_VARTYPE:</c> when
 * they are enabled.
 * </remarks>
 */

#if defined PLAYER_VARTYPE
	_FIXES_HIDE_PAWNDOC(FIXES_PLAYER_VARTYPE_);
#else
	_FIXES_CONST_PAWNDOC(PLAYER_VARTYPE = cellmin);
	#if defined __TAG
		#define PLAYER_VARTYPE: __TAG(PLAYER_VARTYPE):
	#else
		#define PLAYER_VARTYPE: _:
	#endif
#endif

/**
 * <library>fixes.inc</library>
 * <remarks>
 * Future-compatible tag definitions.  <c>BODY_PART:</c> is defined as <c>_:</c>
 * when enhanced tags are disabled, and <c>E_BODY_PART:</c> when they are
 * enabled.
 * </remarks>
 */

#if defined BODY_PART
	_FIXES_HIDE_PAWNDOC(FIXES_BODY_PART_);
#else
	_FIXES_CONST_PAWNDOC(BODY_PART = cellmin);
	#if defined __TAG
		#define BODY_PART: __TAG(BODY_PART):
	#else
		#define BODY_PART: _:
	#endif
#endif

/**
 * <library>fixes.inc</library>
 * <remarks>
 * Future-compatible tag definitions.  <c>CAM_MODE:</c> is defined as <c>_:</c>
 * when enhanced tags are disabled, and <c>E_CAM_MODE:</c> when they are
 * enabled.
 * </remarks>
 */

#if defined CAM_MODE
	_FIXES_HIDE_PAWNDOC(FIXES_CAM_MODE_);
#else
	_FIXES_CONST_PAWNDOC(CAM_MODE = cellmin);
	#if defined __TAG
		#define CAM_MODE: __TAG(CAM_MODE):
	#else
		#define CAM_MODE: _:
	#endif
#endif

/**
 * <library>fixes.inc</library>
 * <remarks>
 * Future-compatible tag definitions.  <c>VEHICLE:</c> is defined as <c>_:</c>
 * when enhanced tags are disabled, and <c>E_VEHICLE:</c> when they are enabled.
 * </remarks>
 */

#if defined VEHICLE
	_FIXES_HIDE_PAWNDOC(FIXES_VEHICLE_);
#else
	_FIXES_CONST_PAWNDOC(VEHICLE = cellmin);
	// `__TAG(VEHICLE):` is not currently in the enhanced SA:MP includes.
	//#if defined __TAG
	//	#define VEHICLE: __TAG(VEHICLE):
	//#else
		#define VEHICLE: _:
	//#endif
#endif

/**
 * <library>fixes.inc</library>
 * <remarks>
 * Future-compatible tag definitions.  <c>CARMODTYPE:</c> is defined as
 * <c>_:</c> when enhanced tags are disabled, and <c>E_CARMODTYPE:</c> when they
 * are enabled.
 * </remarks>
 */

#if defined CARMODTYPE
	_FIXES_HIDE_PAWNDOC(FIXES_CARMODTYPE_);
#else
	_FIXES_CONST_PAWNDOC(CARMODTYPE = cellmin);
	#if defined __TAG
		#define CARMODTYPE: __TAG(CARMODTYPE):
	#else
		#define CARMODTYPE: _:
	#endif
#endif

/**
 * <library>fixes.inc</library>
 * <remarks>
 * Future-compatible tag definitions.  <c>WEAPON:</c> is defined as <c>_:</c>
 * when enhanced tags are disabled, and <c>E_WEAPON:</c> when they
 * are enabled.
 * </remarks>
 */

#if defined WEAPON
	_FIXES_HIDE_PAWNDOC(FIXES_WEAPON_);
#else
	_FIXES_CONST_PAWNDOC(WEAPON = cellmin);
	#if defined __TAG
		#define WEAPON: __TAG(WEAPON):
	#else
		#define WEAPON: _:
	#endif
#endif

/**
 * <library>fixes.inc</library>
 * <remarks>
 * Future-compatible tag definitions.  <c>MAPICON:</c> is defined as <c>_:</c>
 * when enhanced tags are disabled, and <c>E_MAPICON:</c> when they
 * are enabled.
 * </remarks>
 */

#if defined MAPICON
	_FIXES_HIDE_PAWNDOC(FIXES_MAPICON_);
#else
	_FIXES_CONST_PAWNDOC(MAPICON = cellmin);
	#if defined __TAG
		#define MAPICON: __TAG(MAPICON):
	#else
		#define MAPICON: _