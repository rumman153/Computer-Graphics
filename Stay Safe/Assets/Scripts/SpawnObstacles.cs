using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SpawnObstacles : MonoBehaviour
{
    public GameObject obstacle; //contain the obstacle we want to spawn
    public float maxX; //4 variable for spawing within minimum and maximum range
    public float minX;
    public float maxY;
    public float minY;
    public float timeBetweenSpawn; //time to spawn next obstacle
    private float spawnTime;
 

    // Update is called once per frame
    void Update()
    {
        if(Time.time > spawnTime)
        {
            Spawn();
            spawnTime = Time.time + timeBetweenSpawn;
        }
    }

    void Spawn()
    {
        float randomX = Random.Range(minX, maxX); // to spawn at random location within min and max
        float randomY = Random.Range(minY, maxY);

        Instantiate(obstacle, transform.position + new Vector3(randomX, randomY, 0), transform.rotation);
    }
}
