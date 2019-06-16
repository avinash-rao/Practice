.PHONY: clean All

All:
	@echo "----------Building project:[ STL - Debug ]----------"
	@cd "STL" && "$(MAKE)" -f  "STL.mk"
clean:
	@echo "----------Cleaning project:[ STL - Debug ]----------"
	@cd "STL" && "$(MAKE)" -f  "STL.mk" clean
