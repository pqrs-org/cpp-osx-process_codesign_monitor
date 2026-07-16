#include <csignal>
#include <iostream>
#include <pqrs/dispatcher.hpp>
#include <pqrs/osx/process_codesign_monitor.hpp>
#include <pqrs/thread_wait.hpp>

namespace {
auto global_wait = pqrs::make_thread_wait();
}

int main() {
  std::signal(SIGINT, [](int) {
    global_wait->notify();
  });

  pqrs::dispatcher::extra::initialize_shared_dispatcher();

  {
    // The default constructor monitors the current process every second
    // and emits `invalidated` after three consecutive verification failures.
    pqrs::osx::process_codesign_monitor monitor;

    monitor.team_id_changed.connect([](const auto& team_id) {
      if (team_id) {
        std::cout << "Team ID: " << *team_id << std::endl;
      } else {
        std::cout << "Team ID: not available" << std::endl;
      }
    });

    monitor.invalidated.connect([] {
      std::cout << "The process code signature has been invalidated."
                << std::endl;
    });

    monitor.async_start();

    std::cout << "Press Control-C to exit." << std::endl;

    global_wait->wait_notice();
  }

  pqrs::dispatcher::extra::terminate_shared_dispatcher();

  return 0;
}
