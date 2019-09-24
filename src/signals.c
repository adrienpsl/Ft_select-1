/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:16:37 by abarthel          #+#    #+#             */
/*   Updated: 2019/09/20 09:03:36 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include <signal.h>
#include <stdlib.h>

#include "ft_select.h"
#include "libft.h"
#include "libtc.h"

#ifdef __unix__

void	change_winsize(int sig)
{
	(void)sig;
	tc_clear();
	get_window_info(g_display);
	select_loop(g_list, g_display);
}

void	foreground(int sig)
{
	(void)sig;
	init_term(1);
	tc_clear();
	if (signal(SIGTSTP, background) == SIG_ERR)
		exit(2);
	select_loop(g_list, g_display);
}

#else

void	change_winsize(int sig)
{
	(void)sig;
	tc_clear();
	get_window_info(g_display);
	if (it_fits(g_display))
		display_list(g_list, g_display);
	else
		ft_dprintf(g_tc_fd, "Cannot display list, the window is too small");
}

void	foreground(int sig)
{
	(void)sig;
	init_term(1);
	tc_clear();
	if (signal(SIGTSTP, background) == SIG_ERR)
		exit(2);
	display_list(g_list, g_display);
}

#endif

void	background(int sig)
{
	(void)sig;
	tc_clear();
	init_term(0);
	if (signal(SIGTSTP, SIG_DFL) == SIG_ERR)
		exit(2);
	ioctl(g_tc_fd, TIOCSTI, "\032");
}

struct s_sig	g_sigdfl[] =
{
	{ SIGHUP, SIG_DFL},  /*       1       Term    Hangup detected on controlling terminal or death of controlling process */
	{ SIGINT, SIG_DFL},  /*       2       Term    Interrupt from keyboard */
	{ SIGQUIT, SIG_DFL}, /*       3       Core    Quit from keyboard */
	{ SIGILL, SIG_DFL},  /*       4       Core    Illegal Instruction */
	{ SIGABRT, SIG_DFL}, /*       6       Core    Abort signal from abort(3) */
	{ SIGFPE, SIG_DFL},  /*       8       Core    Floating-point exception */
	{ SIGSEGV, SIG_DFL}, /*      11       Core    Invalid memory reference */
	{ SIGPIPE, SIG_DFL}, /*      13       Term    Broken pipe: write to pipe with no readers; see pipe(7) */
	{ SIGALRM, SIG_DFL}, /*      14       Term    Timer signal from alarm(2) */
	{ SIGTERM, SIG_DFL}, /*      15       Term    Termination signal */
	{ SIGUSR1, SIG_DFL}, /*   30,10,16    Term    User-defined signal 1 */
	{ SIGUSR2, SIG_DFL}, /*   31,12,17    Term    User-defined signal 2 */
	{ SIGCHLD, SIG_DFL}, /*   20,17,18    Ign     Child stopped or terminated */
	{ SIGCONT, SIG_DFL}, /*   19,18,25    Cont    Continue if stopped */
	{ SIGTSTP, SIG_DFL}, /*   18,20,24    Stop    Stop typed at terminal */
	{ SIGTTIN, SIG_DFL}, /*   21,21,26    Stop    Terminal input for background process */
	{ SIGTTOU, SIG_DFL}, /*   22,22,27    Stop    Terminal output for background process */
	{ SIGBUS, SIG_DFL},  /*   10,7,10     Core    Bus error (bad memory access) */
	{ SIGPOLL, SIG_DFL}, /*               Term    Pollable event (Sys V). Synonym for SIGIO */
	{ SIGPROF, SIG_DFL}, /*   27,27,29    Term    Profiling timer expired */
	{ SIGSYS, SIG_DFL},  /*   12,31,12    Core    Bad system call (SVr4); see also seccomp(2) */
	{ SIGTRAP, SIG_DFL}, /*      5        Core    Trace/breakpoint trap */
	{ SIGURG, SIG_DFL},  /*   16,23,21    Ign     Urgent condition on socket (4.2BSD) */
	{ SIGVTALRM, SIG_DFL}, /* 26,26,28    Term    Virtual alarm clock (4.2BSD) */
	{ SIGXCPU, SIG_DFL}, /*   24,24,30    Core    CPU time limit exceeded (4.2BSD); see setrlimit(2) */
	{ SIGXFSZ, SIG_DFL}, /*   25,25,31    Core    File size limit exceeded (4.2BSD); see setrlimit(2) */
	{ SIGIOT, SIG_DFL},  /*      6        Core    IOT trap. A synonym for SIGABRT */
/*	{ SIGEMT, SIG_DFL},*/  /*    7,-,7      Term    Emulator trap */
	{ SIGSTKFLT, SIG_DFL}, /*  -,16,-     Term    Stack fault on coprocessor (unused) */
	{ SIGIO, SIG_DFL},   /*   23,29,22    Term    I/O now possible (4.2BSD) */
	{ SIGCLD, SIG_DFL},  /*    -,-,18     Ign     A synonym for SIGCHLD */
	{ SIGPWR, SIG_DFL},  /*   29,30,19    Term    Power failure (System V) */
/*	{ SIGINFO, SIG_DFL},*/ /*    29,-,-             A synonym for SIGPWR */
/*	{ SIGLOST, SIG_DFL},*/ /*    -,-,-      Term    File lock lost (unused) */
	{ SIGWINCH, SIG_DFL},  /* 28,28,20    Ign     Window resize signal (4.3BSD, Sun) */
/*	{ SIGUNUSED, SIG_DFL},*/ /*  -,31,-     Core    Synonymous with SIGSYS */
	{ 0, NULL }
};

void	quit(int sig)
{
	int	i;

	(void)sig;
	init_term(0);
	i = 1;
	while (g_sigdfl[i].f)
	{
		if ((signal(g_sigdfl[i].sig, g_sigdfl[i].f) == SIG_ERR))
			exit(2);
		++i;
	}
	exit(0);
}

struct s_sig	g_siginit[] =
{
	{ SIGHUP, quit},  /*       1       Term    Hangup detected on controlling terminal or death of controlling process */
	{ SIGINT, quit},  /*       2       Term    Interrupt from keyboard */
	{ SIGQUIT, quit}, /*       3       Core    Quit from keyboard */
	{ SIGILL, quit},  /*       4       Core    Illegal Instruction */
	{ SIGABRT, quit}, /*       6       Core    Abort signal from abort(3) */
	{ SIGFPE, quit},  /*       8       Core    Floating-point exception */
	{ SIGSEGV, quit}, /*      11       Core    Invalid memory reference */
	{ SIGPIPE, quit}, /*      13       Term    Broken pipe: write to pipe with no readers; see pipe(7) */
	{ SIGALRM, quit}, /*      14       Term    Timer signal from alarm(2) */
	{ SIGTERM, quit}, /*      15       Term    Termination signal */
	{ SIGUSR1, quit}, /*   30,10,16    Term    User-defined signal 1 */
	{ SIGUSR2, quit}, /*   31,12,17    Term    User-defined signal 2 */
	{ SIGCHLD, SIG_IGN}, /*   20,17,18    Ign     Child stopped or terminated */
	{ SIGCONT, foreground}, /*   19,18,25    Cont    Continue if stopped */
	{ SIGTSTP, background}, /*   18,20,24    Stop    Stop typed at terminal */
	{ SIGTTIN, quit}, /*   21,21,26    Stop    Terminal input for background process */
	{ SIGTTOU, quit}, /*   22,22,27    Stop    Terminal output for background process */
	{ SIGBUS, quit},  /*   10,7,10     Core    Bus error (bad memory access) */
	{ SIGPOLL, quit}, /*               Term    Pollable event (Sys V). Synonym for SIGIO */
	{ SIGPROF, quit}, /*   27,27,29    Term    Profiling timer expired */
	{ SIGSYS, quit},  /*   12,31,12    Core    Bad system call (SVr4); see also seccomp(2) */
	{ SIGTRAP, quit}, /*      5        Core    Trace/breakpoint trap */
	{ SIGURG, SIG_IGN},  /*   16,23,21    Ign     Urgent condition on socket (4.2BSD) */
	{ SIGVTALRM, quit}, /* 26,26,28    Term    Virtual alarm clock (4.2BSD) */
	{ SIGXCPU, quit}, /*   24,24,30    Core    CPU time limit exceeded (4.2BSD); see setrlimit(2) */
	{ SIGXFSZ, quit}, /*   25,25,31    Core    File size limit exceeded (4.2BSD); see setrlimit(2) */
	{ SIGIOT, quit},  /*      6        Core    IOT trap. A synonym for SIGABRT */
/*	{ SIGEMT, quit},*/  /*    7,-,7      Term    Emulator trap */
	{ SIGSTKFLT, quit}, /*  -,16,-     Term    Stack fault on coprocessor (unused) */
	{ SIGIO, quit},   /*   23,29,22    Term    I/O now possible (4.2BSD) */
	{ SIGCLD, SIG_IGN},  /*    -,-,18     Ign     A synonym for SIGCHLD */
	{ SIGPWR, quit},  /*   29,30,19    Term    Power failure (System V) */
/*	{ SIGINFO, quit},*/ /*    29,-,-             A synonym for SIGPWR */
/*	{ SIGLOST, quit},*/ /*    -,-,-      Term    File lock lost (unused) */
	{ SIGWINCH, change_winsize},  /* 28,28,20    Ign     Window resize signal (4.3BSD, Sun) */
/*	{ SIGUNUSED, quit},*/ /*  -,31,-     Core    Synonymous with SIGSYS */
	{ 0, NULL }
};

int		set_signals(void)
{
	int	i;

	i = 1;
	while (g_siginit[i].f)
	{
		if ((signal(g_siginit[i].sig, g_siginit[i].f) == SIG_ERR))
			exit(2);
		++i;
	}
	return (0);
}
