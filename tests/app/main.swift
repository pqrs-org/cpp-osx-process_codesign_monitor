import Darwin
import Foundation

#if PROCESS_CODESIGN_TEST_HELPER_A
let variant = "A"
#elseif PROCESS_CODESIGN_TEST_HELPER_B
let variant = "B"
#else
#error("A process codesign test helper variant must be selected.")
#endif

signal(SIGINT) { _ in
  _exit(0)
}

signal(SIGTERM) { _ in
  _exit(0)
}

FileHandle.standardOutput.write(Data(variant.utf8))

while true {
  pause()
}
