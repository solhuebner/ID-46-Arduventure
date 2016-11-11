## Notes for Arduventure World Implementation

####MAP ENGINE
Chunk size:			| 6x6 tiles
---					| ---
Tile size:			| 16x16 pixels
Map size:			| 32x32 chunks, grid of solid/non-solid
Number of tiles: 	| 48~
Maximum tiles: 		| 1 byte/tile, 256 total


Element					| Bytes Used Per
chunk					| 36
Tile					| 32
Map	 					| 128
Total tiles				| 1,536 (48 tiles)
Cost for Total Tiles	| 8,192

Map will be broken up into regions which determine the tile set used to render solid/non-solid chunks. See Fig.1 The total map size with this configuration would be 3,072 x 3,072 pixels, or 24 horizontal screens, approx 32 vertical screens.

####VILLAGES
Will be incorporated into the solid/non-solid map. Before selecting the chunk based on the surroundings, the chunk selector will go through a switch statement looking for specific predefined chunks based on the coordinates as follows: x + y * width

I may be able to incorporate that into the map editor. The more robust the map editor, the longer it will take to develop, but the easier it would be to create a sequel (Arduventure 2).

		Fig.1 Example Regions
		---------------------------------
		|				|				|
		|				|				|
		|	grasslands	|	Forest		|
		|				|				|
		|				|				|
		---------------------------------
		|				|				|
		|				|				|
		|	lakeside	|	mountains	|
		|				|				|
		|				|				|
		---------------------------------

####NPC's
Game objects like non player characters, world chests, doors, etc. will be allocated and deallocated dynamically to allow for a greater number of game objects without breaking the map into separate pieces. Possibly by region spawners? There could be four (or how many regions there ends up being) spawners that create all the objects in a region once the player has entered into that spawners region. Once the player is no longer in a spawners region, it will deallocate all the objects it had created.

The objects could be stored in arrays as 3 bytes per object. The first byte is broken up unevenly, the first 2 bits are for type (npc, chest, door, etc [up to 4 different types]) and the last 6 bits are for index allowing up to 64 unique objects per type. The second byte is broken up unevenly, the first 5 bits for chunk x, the last 3 for tile in chunk x, the third byte is broken up the same as the second but for the y coordinate.

####World Editor
Allows full creation of the world. Setting region bounds, placing objects, customizing chunks, and setting specific chunks in the world. Specifics below.

* The chunk editor is built into the world editor.
* When placing a specific chunk, the user will be able to select from existing chunks, or create a new
one.
* Will show in real time how many bytes are used by the total chunks.
* Can delete chunks inside the selection list.
* When a chunk is deleted all specific chunks in the world will update to their new index if it was
greater than the index deleted.
* Any specific chunk in the world with the index of a chunk that gets deleted will revert back to non-
specific.
* Specific chunks still have a solid/non-solid flag. This only determines how non-specific tiles see
them.
* Exporting the map creates the entire chunk array ready for progmem.
* Exporting the map creates the switch statement for specific chunks.
* Exporting the map creates the object arrays for each regions spawners.

####Inside Houses
Not handled with this editor and will need to be handled another way.




