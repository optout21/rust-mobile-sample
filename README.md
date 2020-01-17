# rust-mobile-sample
Sample project for Rust-iOS-Android usage

# Usage

## Prerequisites

- Rust

## Get sources

```shell
git clone https://github.com/catenocrypt/rust-mobile-sample.git
cd rust-mobile-sample
```

## iOS

Prerequisites:

- Xcode
- cargo-lipo

```shell
cargo install cargo-lipo
```

Build the Rust library for iOS, universal target, using 

```shell
cd rustgreet
cargo lipo --release
```

Build the iOS sample client

- Open Xcode
- Open project `ios/Greetings/Greetings.xcodeproj`
- Include dir `rustgreet/src` has been added
- Linking with `rustgreet/target/universal/release/libgreetings.a` has been set up
- Linking with `libresolv.tbd` has been set up
- Build the project
- Run the project (with simulator), and check output in the console window

More info:  https://mozilla.github.io/firefox-browser-architecture/experiments/2017-09-06-rust-on-ios.html

## Android

TODO

More info:  https://mozilla.github.io/firefox-browser-architecture/experiments/2017-09-21-rust-on-android.html

## CPP

Build the Rust library

```shell
cd rustgreet
cargo build
```

Build the Rust library

```shell
cd cpp
cmake .
make
```

Run it:

```shell
./rust-greet-cpp 
```
