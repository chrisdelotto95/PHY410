# @(#)Cshrc 6.0 6/2/2000 ECS
#################################################################
#
#         .cshrc file
#
#         initial setup file for both interactive and noninteractive
#         T-Shells on the Engineering UNIX machines running the
#         SunOS, Solaris, or IRIX  operating systems.  Read in after
#         the global /{eng,usr}/local/etc/csh.cshrc files.
#
#################################################################
#
# Set up initial search path (this should match dtlogin's initial path):
#
if ( -f /vmunix ) then
    #
    # SunOS:
    #
    set path = ( /usr/bin /usr/etc /usr/5bin /usr/ucb )
    #
    # Set up the "eng" alias:
    #
    alias eng 'source /util/local/source/eng'
    #
    # Initial man page path:
    #
    setenv MANPATH /usr/local/man:/eng/local/man:/usr/man
    #
    #
    # Set up X Window System/OpenWindows environment variables:
    #
    setenv EXHOME "/eng/tools/X"
    setenv MOTIFHOME "/usr/dt"
    setenv OPENWINHOME "/usr/openwin"
    setenv XHOME "/util/X11"
    set path = ($EXHOME/bin $MOTIFHOME/bin $OPENWINHOME/bin $XHOME/bin $path)
    setenv MANPATH $EXHOME/man:$MOTIFHOME/man:$OPENWINHOME/man:$XHOME/man:$MANPATH
    setenv HELPPATH "$EXHOME/lib/help:$OPENWINHOME/lib/help"
    setenv XFILESEARCHPATH "."
    setenv XFILESEARCHPATH "${XFILESEARCHPATH}:$EXHOME/lib/X11/%L/%T/%N%C%S"
    setenv XFILESEARCHPATH "${XFILESEARCHPATH}:$EXHOME/lib/X11/%l/%T/%N%C%S"
    setenv XFILESEARCHPATH "${XFILESEARCHPATH}:$EXHOME/lib/X11/%T/%N%C%S"
    setenv XFILESEARCHPATH "${XFILESEARCHPATH}:$EXHOME/lib/X11/%L/%T/%N%S"
    setenv XFILESEARCHPATH "${XFILESEARCHPATH}:$EXHOME/lib/X11/%l/%T/%N%S"
    setenv XFILESEARCHPATH "${XFILESEARCHPATH}:$EXHOME/lib/X11/%T/%N%S"
    setenv XFILESEARCHPATH "${XFILESEARCHPATH}:/util/gnu/lib/X11/%T/%N%S"
    setenv XFILESEARCHPATH "${XFILESEARCHPATH}:$MOTIFHOME/lib/%T/%N%S"
    setenv XFILESEARCHPATH "${XFILESEARCHPATH}:$OPENWINHOME/lib/%L/%T/%N%C%S"
    setenv XFILESEARCHPATH "${XFILESEARCHPATH}:$OPENWINHOME/lib/%l/%T/%N%C%S"
    setenv XFILESEARCHPATH "${XFILESEARCHPATH}:$OPENWINHOME/lib/%T/%N%C%S"
    setenv XFILESEARCHPATH "${XFILESEARCHPATH}:$OPENWINHOME/lib/%L/%T/%N%S"
    setenv XFILESEARCHPATH "${XFILESEARCHPATH}:$OPENWINHOME/lib/%l/%T/%N%S"
    setenv XFILESEARCHPATH "${XFILESEARCHPATH}:$OPENWINHOME/lib/%T/%N%S"
    setenv XFILESEARCHPATH "${XFILESEARCHPATH}:$XHOME/lib/X11/%L/%T/%N%C%S"
    setenv XFILESEARCHPATH "${XFILESEARCHPATH}:$XHOME/lib/X11/%l/%T/%N%C%S"
    setenv XFILESEARCHPATH "${XFILESEARCHPATH}:$XHOME/lib/X11/%T/%N%C%S"
    setenv XFILESEARCHPATH "${XFILESEARCHPATH}:$XHOME/lib/X11/%L/%T/%N%S"
    setenv XFILESEARCHPATH "${XFILESEARCHPATH}:$XHOME/lib/X11/%l/%T/%N%S"
    setenv XFILESEARCHPATH "${XFILESEARCHPATH}:$XHOME/lib/X11/%T/%N%S"
else
    if($?tcsh == 0) then
        source /eng/local/etc/csh.cshrc
    endif
endif
#
# Environment variables.
#
# Preferred editor:
setenv EDITOR vi
setenv VISUAL vi
# Preferred pager:
setenv PAGER less
#
# Skip remaining setup if not an interactive shell:
#
if ($?USER == 0 || $?prompt == 0) exit
#
# Settings for interactive shells:
#
set ignoreeof
#
# Tcsh settings.
#
if($?tcsh) then
    #
    # These settings are very useful:
    #
    set autoexpand correct=cmd
endif
#
# Source the user's .aliases file if it exists; this file is where all
# custom commands should go:
#
if (! $?NOSETALIASES) if (-f ~/.aliases ) source ~/.aliases
