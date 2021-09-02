_pkgname=dmenu
pkgname=$_pkgname-mcaimi
pkgver=74ccb1d
pkgrel=1
pkgdesc="Private fork of Suckless' dmenu tool, a dynamic menu for X"
url="https://github.com/mcaimi/dmenu.git"
arch=('i686' 'x86_64')
license=('MIT')
depends=('sh' 'libxinerama' 'libxft')
makedepends=('git')
provides=($_pkgname-git)
conflicts=($_pkgname)
source=(git+https://github.com/mcaimi/dmenu)
sha256sums=('SKIP')

pkgver() {
  cd $_pkgname
  git rev-parse --short HEAD
}

prepare() {
  cd $_pkgname
  # to use a custom config.h, place it in the package directory
  if [[ -f ${SRCDEST}/config.h ]]; then
      cp "${SRCDEST}/config.h" .
  fi
}

build(){
  cd $_pkgname
  make \
    X11INC=/usr/include/X11 \
    X11LIB=/usr/lib/X11
}

package() {
  cd $_pkgname
  make PREFIX=/usr DESTDIR="$pkgdir" install
  install -Dm644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
