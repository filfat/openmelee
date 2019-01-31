# openmelee
[![Build Status](https://travis-ci.org/filfat/openmelee.svg?branch=master)](https://travis-ci.org/filfat/openmelee)  [![Twitch](https://img.shields.io/badge/watch%20me%20on-Twitch-%236441A4.svg)](https://www.twitch.tv/filiphsandstrom)

(Really early) Attempt at an open source Super Smash Bros. Melee reimplementation.

## Building
    $ meson buildir && ninja -C builddir
 
## Contributing
### Acquiring original source
A automated tool fro decompiling and renaming the re:d functions to human-readable-names will be developed and provieded in the future, for now use the map file(s) from [here](https://smashboards.com/threads/smashboards-community-symbol-map.426763/).
### Styleguide
This isn't really decided upon yet, see issue #3. Basically, try to stick to the codestyle used in the current file you're working on. Also, try not to add more dependencies unless absolutely necessary (or the alternative requires a huge implementation).

## License
Currently licensed under Mozilla Public License 2.0, will probably change to MIT in the future depending on community feedback.
