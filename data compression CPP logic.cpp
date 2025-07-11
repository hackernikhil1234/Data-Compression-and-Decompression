#include <iostream>
#include <string>
#include <cctype>

// Run-Length Encoding (RLE) Compression
std::string rleCompress(const std::string& text) {
    if (text.empty()) return "";

    std::string result;
    int count = 1;
    char current = text[0];

    for (size_t i = 1; i < text.length(); ++i) {
        if (text[i] == current) {
            count++;
        } else {
            if (count > 1) {
                result += std::to_string(count);
            }
            result += current;
            current = text[i];
            count = 1;
        }
    }

    // Append the last sequence
    if (count > 1) {
        result += std::to_string(count);
    }
    result += current;

    return result;
}

// Run-Length Encoding (RLE) Decompression
std::string rleDecompress(const std::string& text) {
    if (text.empty()) return "";

    std::string result;
    std::string countStr;

    for (size_t i = 0; i < text.length(); ++i) {
        if (isdigit(text[i])) {
            countStr += text[i];
        } else {
            int count = countStr.empty() ? 1 : std::stoi(countStr);
            result.append(count, text[i]);
            countStr.clear();
        }
    }

    return result;
}

int main() {
    std::string input;
    std::cout << "Enter text to compress: ";
    std::getline(std::cin, input);

    std::string compressed = rleCompress(input);
    std::cout << "Compressed: " << compressed << std::endl;

    std::string decompressed = rleDecompress(compressed);
    std::cout << "Decompressed: " << decompressed << std::endl;

    return 0;
}
