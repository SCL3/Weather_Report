/////////// NODE Functions ////////////////////////////////////////

#include "head.h"

Node* createNode(int val, Mto* meteo){
	Node* pNew = malloc(sizeof(Node));
	if(pNew == NULL){  // Check if the malloc worked
		exit(4);
	}
	pNew -> value = val;
	pNew -> Meteo = meteo;
	pNew -> pNext = NULL;
	return pNew;
}

Node* asc_insertNode(Node* pHead, int val, Mto* meteo){  //Node will be sorted in an ascending order
	if(pHead == NULL){  // Check if the head is not empty
		return createNode(val, meteo);
	} 
	else if(val < pHead -> value){  // Add the value to the head
		Node* pNew = createNode(val, meteo);
       		pNew -> pNext = pHead;
       		pHead = pNew;
       		return pHead;
   	}
   	else if(val == pHead -> value){  //if they have the same value
   		if(meteo -> value_sorted == 1){  //Sort mode for the Height
			if(meteo -> station < pHead -> Meteo -> station){
				Node* pNew = createNode(val, meteo);
       				pNew -> pNext = pHead;
       				pHead = pNew;
       				return pHead;
			}
			else if(meteo -> station == pHead -> Meteo -> station){  //if the value and the station is the same
				return pHead;
			}
			else{
				pHead -> pNext = asc_insertNode(pHead -> pNext, val, meteo);
			}
		}
		if(meteo -> value_sorted == 2){  //Sort mode for the Moisture
			if(meteo -> moisture > pHead -> Meteo -> moisture){  //Replace the lowest moisture value with the highest 
				pHead -> Meteo -> moisture = meteo -> moisture;
			}
		}
		else if(meteo -> value_sorted == 3){  //Sort mode for the wind
			if(meteo -> wind_direction == -1 && meteo -> wind_speed == -1){  //If there is no data in the wind slot
				return pHead;
			}
			else if(meteo -> wind_direction == -1){  //If there is only speed
				pHead -> Meteo -> wind_speed += meteo -> wind_speed;
				pHead -> Meteo -> counter_speed += 1; 
				return pHead;
			}
			else if(meteo -> wind_speed == -1){  //If there is only direction
				pHead -> Meteo -> wind_direction += meteo -> wind_direction;
				pHead -> Meteo -> counter_direction += 1; 
				return pHead;
			}
			pHead -> Meteo -> wind_direction += meteo -> wind_direction;  //Add the speed and the direction, to make a total 
			pHead -> Meteo -> wind_speed += meteo -> wind_speed;
			pHead -> Meteo -> counter_direction += 1; 
			pHead -> Meteo -> counter_speed += 1; 
			return pHead;
		}
   	}
	else if(pHead -> pNext == NULL){ // Check if there is only 1 node
     		pHead -> pNext = createNode(val, meteo);
           	return pHead;
        }
        else{
        	pHead -> pNext = asc_insertNode(pHead -> pNext, val, meteo);
    	}
    	return pHead;
}

Node* desc_insertNode(Node* pHead, int val, Mto* meteo){  //Node will be sorted in an descending order
	if(pHead == NULL){  // Check if the head is not empty
		return createNode(val, meteo);
	} 
	else if(val > pHead -> value){  // Add the value to the head
		Node* pNew = createNode(val, meteo);
       		pNew -> pNext = pHead;
       		pHead = pNew;
       		return pHead;
   	}
   	else if(val == pHead -> value){  //if they have the same value
   		if(meteo -> value_sorted == 1){  //Sort mode for the Height
			if(meteo -> station > pHead -> Meteo -> station){
				Node* pNew = createNode(val, meteo);
       				pNew -> pNext = pHead;
       				pHead = pNew;
       				return pHead;
			}
			else if(meteo -> station == pHead -> Meteo -> station){  //if the value and the station is the same
				return pHead;
			}
			else{
				pHead -> pNext = desc_insertNode(pHead -> pNext, val, meteo);
			}
		}
		else if(meteo -> value_sorted == 2){  //Sort mode for the Moisture
			if(meteo -> moisture > pHead -> Meteo -> moisture){  //Replace the lowest moisture value with the highest 
				pHead -> Meteo -> moisture = meteo -> moisture;
			}
		}
		else if(meteo -> value_sorted == 3){  //Sort mode for the wind
			if(meteo -> wind_direction == -1 && meteo -> wind_speed == -1){  //If there is no data in the wind slot
				return pHead;
			}
			else if(meteo -> wind_direction == -1){  //If there is only speed
				pHead -> Meteo -> wind_speed += meteo -> wind_speed;
				pHead -> Meteo -> counter_speed += 1; 
				return pHead;
			}
			else if(meteo -> wind_speed == -1){  //If there is only direction
				pHead -> Meteo -> wind_direction += meteo -> wind_direction;
				pHead -> Meteo -> counter_direction += 1; 
				return pHead;
			}
			pHead -> Meteo -> wind_direction += meteo -> wind_direction;  //Add the speed and the direction, to make a total 
			pHead -> Meteo -> wind_speed += meteo -> wind_speed;
			pHead -> Meteo -> counter_direction += 1; 
			pHead -> Meteo -> counter_speed += 1; 
			return pHead;
		}
		
   	}
	else if(pHead -> pNext == NULL){ // Check if there is only 1 node
     		pHead -> pNext = createNode(val, meteo);
           	return pHead;
        }
        else{
        	pHead -> pNext = desc_insertNode(pHead -> pNext, val, meteo);
    	}
    	return pHead;
}

void desc_recreateNode(Node** pHead, Node* pHead_tmp){
	if(pHead_tmp != NULL){
		pHead_tmp -> Meteo -> value_sorted = 1;  //Change the value to recreate the node with the Height sort method
		*pHead = desc_insertNode(*pHead, pHead_tmp -> Meteo -> moisture, pHead_tmp -> Meteo); 
		desc_recreateNode(pHead, pHead_tmp -> pNext);
	}
}

void asc_recreateNode(Node** pHead, Node* pHead_tmp){
	if(pHead_tmp != NULL){
		pHead_tmp -> Meteo -> value_sorted = 1;  //Change the value to recreate the node with the Height sort method
		*pHead = asc_insertNode(*pHead, pHead_tmp -> Meteo -> moisture, pHead_tmp -> Meteo); 
		asc_recreateNode(pHead, pHead_tmp -> pNext);
	}
}

Node* averageNode(Node* pHead){
	if(pHead != NULL){
		pHead -> Meteo -> wind_direction /= pHead -> Meteo -> counter_direction;
		pHead -> Meteo -> wind_speed /= pHead -> Meteo -> counter_speed;
		pHead -> pNext = averageNode(pHead -> pNext);
		return pHead;
	}
}

void displayList(Node* pHead){
    while(pHead != NULL){
        printf("[%d (%lf)]->", pHead -> value, pHead -> Meteo -> wind_direction);
        pHead = pHead -> pNext;
    }
    printf("\n");
}
