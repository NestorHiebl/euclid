# Self documenting makefile format based on the article by François Zaninotto
# https://marmelab.com/blog/2016/02/29/auto-documented-makefile.html

CFLAGS := -Wall -Wextra -pedantic -Werror -std=c99
HFLAGS := -Wall -Wno-unused-top-binds -Werror

.DEFAULT_GOAL := help

.PHONY: compile help clean

help: ## Print makefile and target info
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | \
	awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'

compile: ## Compile all sources
	gcc $(CFLAGS) -o c.out euclid.c
	ghc $(HFLAGS) -o hs.out euclid.hs

clean: ## Clean build directory
	rm *.o *.out *.hi

