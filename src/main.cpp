#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
  // Flush after every std::cout / std::cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  // You can use print statements as follows for debugging, they'll be visible
  // when running tests.
  std::cerr << "Logs from your program will appear here" << std::endl;

  if (argc != 3) {
    std::cerr << "Expected two arguments" << std::endl;
    return 1;
  }

  std::string database_file_path = argv[1];
  std::string command = argv[2];

  if (command == ".dbinfo") {
    std::ifstream database_file{database_file_path, std::ios::binary};

    if (!database_file) {
      std::cerr << "Failed to open the database file" << '\n';
      return 1;
    }

    database_file.seekg(16); // Skip the first 16 bytes of the header

    char buffer[2];
    database_file.read(buffer, 2);

    unsigned short page_size = (static_cast<unsigned char>(buffer[1]) |
                                (static_cast<unsigned char>(buffer[0]) << 8));

    std::cout << "database page size: " << page_size << '\n';

    std::vector<char> page(page_size);

    database_file.seekg(103);
    char cells[2];
    database_file.read(cells, 2);

    int number_of_cells = (static_cast<unsigned char>(cells[1])) |
                          (static_cast<unsigned char>(cells[0]) << 8);

    std::cout << "number of tables: " << number_of_cells << '\n';
  }

  return 0;
}
