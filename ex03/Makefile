# Compilador
CXX = c++

# Flags del compilador
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Nombre del ejecutable
NAME = bsp

# Directorio de objetos
OBJDIR = obj

# headers
HEADER_DIR = inc/

# Archivos fuente
SRCS = main.cpp Fixed.cpp Point.cpp bsp.cpp

# Archivos objeto generados
OBJS = $(patsubst %.cpp,$(OBJDIR)/%.o,$(SRCS))

# Regla por defecto
all: $(NAME)

# Regla para generar el ejecutable
$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "✔ Ejecutable $(NAME) creado."

# Regla para compilar archivos .cpp a .o
$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -I$(HEADER_DIR) -c $< -o $@
	@echo "✔ Compilado $<"

clean:
	@rm -rf $(OBJS) $(OBJDIR)
	@echo "🗑 Archivos objeto eliminados."

fclean: clean
	@rm -f $(NAME)
	@echo "🗑 Ejecutable eliminado."

re: fclean all

.PHONY: all clean fclean re
