A minimal system fetch tool written in C.

<img width="576" height="360" alt="image" src="https://github.com/user-attachments/assets/cca4488b-0e33-4fac-a0f2-e0f97d4e0201" />

## Build & Install

```sh
make              # Build
make run          # Build and run
sudo make install # Install to /usr/local/bin
```

## Uninstall

```sh
sudo make uninstall
```

## About

mfet is a small system fetch utility for Linux written entirely in C.

I started this project because I wanted to learn more about Linux and low-level programming. Instead of relying on external commands, mfet reads information directly from files in the Linux filesystem.

The goal isn't to compete with tools like Neofetch or Fastfetch. It's simply a fun project where I can experiment, learn, and gradually build something useful.

## What it currently shows

* User and hostname
* Operating system
* CPU information
* Memory usage
* System uptime
* A tiny cat :)

## Roadmap

Things I'd like to add in the future:

* Distro-specific ASCII logos
* GPU information
* Installed package count
* Better formatting and colors
* More system information

## Why this project exists

mfet began as a learning project and quickly became a great interest of mine.

Every feature is implemented from scratch as I learn new concepts, so the codebase intentionally stays small and easy to understand. Building mfet has been a fun way to explore Linux internals, improve my C skills, and create something useful along the way.

---

If you found this project interesting, consider giving it a star ⭐

Hope you like it! <3
```
 /\_/\\
( o.o ) A hug by Lucas Arcoverde
 > ^ <
```
