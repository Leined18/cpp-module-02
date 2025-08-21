# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/20 12:00:00 by usuario           #+#    #+#              #
#    Updated: 2025/08/21 12:07:09 by danpalac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilador
CXX = c++

# Flags del compilador
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Nombre del ejecutable
NAME = fixed

# Directorio de objetos
OBJDIR = obj

#headers
HEADER_DIR = inc/ 

# Archivos fuente
SRCS = main.cpp Fixed.cpp

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

# Limpiar archivos objeto
clean:
	@rm -rf $(OBJS) $(OBJDIR)
	@echo "🗑 Archivos objeto eliminados."

# Limpiar todo, incluyendo el ejecutable
fclean: clean
	@rm -f $(NAME)
	@echo "🗑 Ejecutable eliminado."

# Reconstruir todo
re: fclean all

# Evita conflictos con archivos llamados clean, fclean, etc.
.PHONY: all clean fclean re
