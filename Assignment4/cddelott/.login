# @(#)Login 5.5 8/1/96 ECS
##################################################################
#
#         .login file
#
#         Read in after the .cshrc file when you log in.
#         Not read in for subsequent shells.  For setting up
#         terminal and global environment characteristics.
#
##################################################################
#
# Terminal characteristics for remote terminals:
#
if (! $?TERM) then
   setenv TERM vt100
endif
#
if ($TERM != "sun" && $TERM != "xterm") then
    if ( -f /vmunix )   then     # must be on SunOS
        set noglob
        eval `tset -s -m 'network:?vt100'`
        unset noglob
    else                             # must be on Solaris 2
        if ($TERM == "network" || $TERM == "unknown") then
            setenv TERM vt100
            echo -n "set terminal = ($TERM) "
            set termsel = $<
            if ("$termsel" == "") then
                tput init
            else
                setenv TERM $termsel; tput init
            endif
        endif
    endif
endif
#
# General terminal characteristics:
#
if ( ! -f /vmunix )   then     # must be on Solaris
   stty -istrip 
endif
#
# See who is logged in:
#
# w         
#
# Start window manager if we're not using dtlogin:
#
if ("`tty`" != "/dev/console") exit
if ("$TERM" != "sun") exit
if(! $?DTUSERSESSION) then
    if (-f /eng/local/bin/wm) then
       /eng/local/bin/wm
    else if ( -f /util/local/bin/wm) then
       /util/local/bin/wm
    endif
endif
