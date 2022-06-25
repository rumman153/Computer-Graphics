using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player : MonoBehaviour
{
    public float playerSpeed; //this will dictate how fast the player is moving
    private Rigidbody2D rb; //to use very simple physics to move our player
    private Vector2 playerDirection; //this will be used to process our player's input

    // Start is called before the first frame update
    void Start()
    {
        rb = GetComponent<Rigidbody2D>(); //fetch the rigidbody2d from "Player" game object
    }

    // Update is called once per frame
    void Update()
    {
        float directionY = Input.GetAxisRaw("Vertical"); //get direction input from keyboard. if up arrow is pressed 1 if down arrow is pressed -1
        playerDirection = new Vector2(0, directionY).normalized; //x will be 0 as the player only moves vertical    
    }
    //"FixedUpdate" is used for being in step with the physics engine rigidbody
    void FixedUpdate()
    {
        rb.velocity = new Vector2(0, playerDirection.y * playerSpeed);
    }
}