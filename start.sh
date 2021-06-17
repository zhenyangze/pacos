#! /bin/sh
#
# build.sh
# Copyright (C) 2021 zhenyangze <zhenyangze@gmail.com>
#
# Distributed under terms of the MIT license.
#


phpize
./configure --with-php-config=$PHPCONFIG_PATH
make clean
make 

sudo make install

#phpbrew fpm restart