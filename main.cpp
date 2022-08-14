#include <iostream>
#include <string>
#include <cpr/cpr.h>

int main() {
    std::string request;
    cpr::Response r;
    do {
        std::cout << "Enter request (get, post, put, delete, patch, exit):" << std::endl;
        std::cin >> request;
        if (request == "get") {
            r = cpr::Get(cpr::Url("http://httpbin.org/get"));
        } else if (request == "post") {
            r = cpr::Post(cpr::Url("http://httpbin.org/post"));
        } else if (request == "put") {
            r = cpr::Put(cpr::Url("http://httpbin.org/put"));
        } else if (request == "delete") {
            r = cpr::Delete(cpr::Url("http://httpbin.org/delete"));
        } else if (request == "patch") {
            r = cpr::Patch(cpr::Url("http://httpbin.org/patch"));
        } else if (request != "exit") {
            std::cout << "Incorrect request." << std::endl;
        }
        if (request != "exit") {
            std::cout << r.text;
        }
    } while (request != "exit");
    return 0;
}
