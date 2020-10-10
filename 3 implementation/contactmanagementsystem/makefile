SRC = unity/unity.c\
src/contactmanagementsystem.c\
test/test_contactmanagementsystem.c\
main.c

INC = -Iunity\
-Iinc\
-Itest

PROJECT_NAME = CONTACTMANAGEMENTSYSTEM.exe

$(PROJECT_NAME):$(SRC)
	gcc $(SRC) $(INC) -o $(PROJECT_NAME)
run : $(PROJECT_NAME)
	./${PROJECT_NAME}
doc:
	make -C documentation
clean:
	rm -rf $(PROJECT_NAME) documentation/html