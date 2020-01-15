// Copyright © 2017-2020 Catenocrypt
// The full copyright notice, including terms governing use, modification, and redistribution,
// is contained in the file LICENSE at the root of the source code distribution tree.
//
// Cpp-language sample app using a Rust library.

#include <rustgreet.h>
#include <iostream>

using namespace std;

string sayHello(const string& to) {
    const char* res = rust_greeting(to.c_str());
    string resStr = res;
    rust_greeting_free(res);
    return resStr;
}

int main() {
    cout << "Rust-Cpp sample" << endl;

    string greeting = rust_greeting("World");
void rust_greeting_free(char* greeting);

}
