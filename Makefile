all:	
		@$(MAKE) -C ./src/shared
		@$(MAKE) -C ./src/checker
		@$(MAKE) -C ./src/push_swap
		cp ./src/push_swap/push_swap ./push_swap
		cp ./src/checker/checker ./checker

clean:	
		@$(MAKE) clean -C ./src/shared
		@$(MAKE) clean -C ./src/checker
		@$(MAKE) clean -C ./src/push_swap

fclean:	
		@$(MAKE) fclean -C ./src/shared
		@$(MAKE) fclean -C ./src/checker
		@$(MAKE) fclean -C ./src/push_swap

re:
	@make fclean
	@make all

.PHONY: all clean fclean re