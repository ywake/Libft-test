############
# Settings #
############

LIBFT_DIR	:= ../

#############
# Variables #
#############

G_TEST_DIR	:= ./.google_test
G_VER		:= release-1.11.0
G_VER_FULL	:= googletest-$(G_VER)
G_TEST		:= $(G_TEST_DIR)/gtest $(G_TEST_DIR)/$(G_VER_FULL)

TESTDIR		:= ./
SRCS		:= $(wildcard $(TESTDIR)*.cpp)
OBJS		:= $(SRCS:%.cpp=%.o)

CXX			:= clang++
INCLUDES	:= -I$(G_TEST_DIR) -I$(LIBFT_DIR)
LIBS		:= -L$(LIBFT_DIR) -lft -lpthread
CXXFLAG		:= -std=c++11 -g -Wno-writable-strings $(INCLUDES) $(LIBS)
LEAK_OPTION	:=


NAME		:= a.out
LIBFT		:= $(LIBFT_DIR)/libft.a

#################
# General rules #
#################

%.o: %.cpp
	@printf "$(THIN)$(ITALIC)"
	$(CXX) $(CXXFLAG)  -c $< -o $@
	@printf "$(END)"

test: all
	./$(NAME)

$(LIBFT):
	$(MAKE) bonus -C $(LIBFT_DIR)

$(G_TEST):
	mkdir -p $(G_TEST_DIR)
	curl -OL https://github.com/google/googletest/archive/refs/tags/$(G_VER).tar.gz
	tar -xvzf $(G_VER).tar.gz $(G_VER_FULL)
	$(RM) $(G_VER).tar.gz
	python $(G_VER_FULL)/googletest/scripts/fuse_gtest_files.py $(G_TEST_DIR)
	mv $(G_VER_FULL) $(G_TEST_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(G_TEST) $(OBJS)
	$(CXX) $(CXXFLAG) $(OBJS) \
		$(G_TEST_DIR)/$(G_VER_FULL)/googletest/src/gtest_main.cc \
		$(G_TEST_DIR)/gtest/gtest-all.cc \
		$(CXXFLAG) -o $(NAME)

clean: FORCE
	$(RM) $(OBJS)

fclean: clean
	$(RM) -r $(NAME) $(NAME).dSYM

re: fclean all

.PHONY: FORCE
FORCE:

##########
# Colors #
##########

END		= \e[0m
BOLD	= \e[1m
THIN	= \e[2m
ITALIC	= \e[3m
U_LINE	= \e[4m
BLACK	= \e[30m
RED		= \e[31m
GREEN	= \e[32m
YELLOW	= \e[33m
BLUE	= \e[34m
PURPLE	= \e[35m
CYAN	= \e[36m
WHITE	= \e[37m
