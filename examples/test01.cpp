#include "tarball.h"
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <cassert>

// Create an archive and verify it grows

int main(int argc, char **argv) {
  (void)argc;
  (void)argv;
  /* open file for writing */
  std::stringstream out;
  /* create the tar file */
  lindenb::io::Tar tarball(out);
  /* add item 1 */
  tarball.put("myfiles/item1.txt", "Hello World 1\n");
  assert(out.str().size() == 1024);
  /* add item 2 */
  tarball.put("myfiles/item2.txt", "Hello World 2\n");
  assert(out.str().size() == 2048);

  /* finalize the tar file */
  tarball.finish();
  // should have increased size by two more blocks
  assert(out.str().size() == 3072);
  /* close the file */

  std::cout<< "Self test passed" << std::endl;
  /* we're done */
  return EXIT_SUCCESS;
  ;
}
