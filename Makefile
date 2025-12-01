aaa:
	@echo Heya! Run 'make [day number]-[chapter]'

all: 1

# Combined days
1: 1-1 1-2

# Individual days/chapters
1-1:
	$(call run_day,1,1)
1-2:
	$(call run_day,1,2)

define run_day
	@cc day-$(1)/$(2).c common.c common.h -o program.o
	@echo -- Running day $(1)-$(2) --
	@./program.o
endef