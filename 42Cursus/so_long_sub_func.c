
void	printmap(t_map *map)
{
	t_pos *temp;
	int counter;
	printf("size_x: %zu\n", map->size_x);
	printf("size_y: %zu\n", map->size_y);
	printf("obstacles:\n");
	temp = map->obstacles;
	counter = 0;
	while (temp != NULL)
	{
		printf("obstacles[%d] x:%zu y:%zu\n", counter, temp->x, temp->y);
		temp = temp->next;
		counter++;
	}
	printf("enemies:\n");
	temp = map->enemies;
	counter = 0;
	while (temp != NULL)
	{
		printf("enemies[%d] x:%zu y:%zu\n", counter, temp->x, temp->y);
		temp = temp->next;
		counter++;
	}
	printf("exits:\n");
	temp = map->exits;
	counter = 0;
	while (temp != NULL)
	{
		printf("exits[%d] x:%zu y:%zu\n", counter, temp->x, temp->y);
		temp = temp->next;
		counter++;
	}
	printf("collectibles:\n");
	temp = map->collectibles;
	counter = 0;
	while (temp != NULL)
	{
		printf("exits[%d] x:%zu y:%zu\n", counter, temp->x, temp->y);
		temp = temp->next;
		counter++;
	}
	printf("==================\n\n");
}