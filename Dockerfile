FROM archlinux:base-devel

LABEL version="0.1.0"
LABEL repository="https://github.com/openair-collective/openair-cyan"
LABEL homepage="https://github.com/openair-collective/openair-cyan"
LABEL maintainer=""

COPY LICENSE.txt README.md /

COPY script /script
COPY providers /providers
COPY entrypoint.sh /

ENTRYPOINT ["/entrypoint.sh"]