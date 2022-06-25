using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraMovement : MonoBehaviour
{
    
    public float cameraSpeed; //how fast camera will be moving

    // Update is called once per frame
    void Update()
    {
        transform.position += new Vector3(cameraSpeed * Time.deltaTime, 0, 0); //camera will move on X axis
    }
}
