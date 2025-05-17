#pragma once

#include <csignal>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

class SignalHandling {
 public:
  SignalHandling() {
    for (const auto sig :
         std::vector<int>{SIGABRT, SIGBUS, SIGFPE, SIGILL, SIGIOT, SIGQUIT,
                          SIGSEGV, SIGSYS, SIGTRAP, SIGXCPU, SIGXFSZ}) {
      struct sigaction action;
      memset(&action, 0, sizeof action);
      action.sa_flags =
          static_cast<int>(SA_SIGINFO | SA_ONSTACK | SA_NODEFER | SA_RESETHAND);
      sigfillset(&action.sa_mask);
      sigdelset(&action.sa_mask, sig);
      action.sa_sigaction = &sig_handler;
      sigaction(sig, &action, nullptr);
    }
  }

  static void sig_handler(int signo, siginfo_t *info, void *_ctx) {
    char cmd[256];
    snprintf(cmd, sizeof(cmd),
             "gdb -p %d -batch -ex 'bt' -ex 'detach' -ex 'quit'", getpid());
    system(cmd);
    _exit(EXIT_FAILURE);
  }
};
