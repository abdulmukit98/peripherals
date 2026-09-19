https://www.youtube.com/watch?v=9kBakyre3WA&t=641s
<br>

Install IPCamera bindings <br>
Goto Things => Add Items  <br>
Select ONVIF Camera       <br>
* Give Ipcamera IP adress
* Camera's own username & password
* ONVIF Port 2020
* ONVIF MEDIA Profile 0
* FFMPEG install location
* C:\Users\ACER\AppData\Local\Microsoft\WinGet\Packages\Gyan.FFmpeg_Microsoft.Winget.Source_8wekyb3d8bbwe\ffmpeg-8.1.1-full_build\bin/ffmpeg.exe
* Then save Things

### GoTo Channels and add all channels and items.
Add widget from developer tools => widget. 
````
uid: CameraKlein
props:
  parameters:
    - description: http://172.17.0.1:81/ipcamera.jpg
      label: Thumbnail URL
      name: thumbnailURL
      required: true
      type: TEXT
    - description: http://172.17.0.1:81/snapshots.mjpeg
      label: Stream URL
      name: streamURL
      required: true
      type: TEXT
    - context: item
      label: Item to Switch
      name: switchItem
      required: false
      type: TEXT
    - context: item
      label: Camera Controls
      name: camera
      required: false
      type: TEXT
  parameterGroups: []
timestamp: Mar 3, 2021, 10:32:37 PM
component: f7-card
config:
  style:
    --f7-card-margin-horizontal: 0px
    width: 16rem
    height: 9rem
slots:
  default:
    - component: oh-image-card
      config:
        lazy: true
        style:
          margin: 0px
          border-radius: 6px
          width: 100%
          height: 9rem
        url: =props.thumbnailURL
        action: photos
        actionPhotos: =[props.streamURL]
        actionPhotoBrowserConfig:
          lazy: true
          theme: dark
          type: popup
    - component: f7-card-content
    - component: oh-link
      config:
        style:
          position: absolute
          top: 0rem
          left: 0.2rem
          color: "=(items[props.switchItem].state === 'ON') ? 'cyan' : 'white'"
          opacity: "=(items[props.switchItem].state === 'ON') ? '0.4' : '0.3'"
        visible: =props.switchItem !== undefined
        iconF7: power
        iconSize: 25
        action: toggle
        actionItem: =props.switchItem
        actionCommand: ON
        actionCommandAlt: OFF
    - component: oh-link
      config:
        visible: =props.camera !== undefined
        style:
          position: absolute
          top: 0rem
          right: 0.2rem
          color: white
          opacity: 0.4
        iconF7: gear_alt
        iconSize: 25
        action: group
        actionGroupPopupItem: =props.camera
    - component: oh-link
      config:
        style:
          position: absolute
          top: 7.8rem
          right: 0.2rem
          color: white
          opacity: "=(items[props.camera + '_MotionAlarm'].state === 'ON') ? '0.5' : '0'"
        iconF7: eye
        iconSize: 18
    - component: oh-link
      config:
        style:
          position: absolute
          top: 7.7rem
          left: 0rem
          color: white
          opacity: "=(items[props.camera + '_AudioAlarm'].state === 'ON') ? '0.5' : '0'"
        iconF7: ear
        iconSize: 18
````

Then Add This Widget
````
uid: CameraGross
tags: []
props:
  parameters:
    - context: item
      description: The Camera Equipment Item
      label: Item
      name: item
      required: false
      type: TEXT
  parameterGroups: []
timestamp: Mar 5, 2021, 12:35:58 PM
component: f7-block
config:
  style:
    --f7-button-text-color: var(--f7-text-color)
    --f7-button-bg-color: var(--f7-card-bg-color)
    --f7-theme-color-rgb: var(--f7-color-blue-rgb)
  class:
    - no-padding
slots:
  default:
    - component: f7-row
      config:
        class:
          - margin
      slots:
        default:
          - component: f7-col
            slots:
              default:
                - component: oh-image
                  config:
                    class:
                      - margin
                      - no-padding
                    lazy: true
                    lazyFadeIn: true
                    url: =items[props.item + "_MJPEG_URL"].state
````

<br>
<br>
<br>
http://localhost:8080/ipcamera/425ac0bdb8/ipcamera.jpg
<br>
http://localhost:8080/ipcamera/425ac0bdb8/ipcamera.mjpeg
<br>
<br>
