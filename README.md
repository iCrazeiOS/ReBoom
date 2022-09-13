# ReBoom
#### Bring new life to Boom!

'**Boom!**' is an iOS game that abandoned by its developers a few years ago, and its servers are no longer online.

ReBoom adds new functionality and fixes to the game.

#### Current features:
- Custom server (hosted by Banana)
- Ability to load custom levels
	- Levels can be created via [This tool](https://github.com/lachylegend/Boom-Level-Editor)
- Full TAS recording/replay functionality
- Keyboard controls (for iPads & Apple Silicon Macs)
- Easy way to reset a level's ghost
- 'Unpatch' the pause bug
- Disables iCloud/Game Centre connectivity
- Replaces in-app purchase functionality (now just gives you coins)
- Custom options within the game's settings menu

#### Installation:
- **With a jailbreak:**
	1) Install **Boom!** (either from the App Store, or by using **Vanilla.ipa** from this repo)
	2) Install **ReBoom** from [My Boom Repo](https://boom.icrazeios.com/)
	3) (Optional) Install **Boom Fullscreen Patch** from the same repo. This will add support for the screen resolution of newer iOS devices.
- **Without a jailbreak:**
	- NOTE: *There are a few ways to install ReBoom without a jailbreak, but I will only be covering **Sideloadly**/**Jailbreaks.app**. If you know how to use other methods, such as AltStore, feel free. Just make sure that you do not change the bundle ID of the app.
	- **Method one (Jailbreaks.app):**
		- This method is the easiest, and does not require a computer. Downside is that it will not always work, as Apple try their best to stop third party app distribution. Any error during this process likely means that Apple has temporarily broken the website.
		###
		1) Visit **https://jailbreaks.app** on your iOS device.
		2) Click on the '**Apps**' tab at the bottom.
		3) Click on the '**Other**' section.
		4) Click on ReBoom and press **'GET'**.
		5) Once installed, you may have to 'trust' the app. To do this, open Settings, and navigate to **General -> Device Management** (may have a slightly different name - it's near the bottom). Then click on the profile, and press trust a few times.
		6) Once you have trusted it, you should be able to launch **Boom!** from your homescreen.
	- **Method two (Sideloadly):**
		1) Install & launch [**Sideloadly**](https://sideloadly.io/#download) on your computer.
		2) Connect your device to the computer, and trust the device if necessary.
		3) Download the **Vanilla.ipa** file from this repo, and select it in the top-left of Sideloadly.
		4) Download the latest file from the **packages** folder of this repo. Open the **advanced options** of Sideloadly, enable **Inject dylibs/frameworks**, and drag the deb file you just downloaded into the empty box.
		5) Make sure your device is selected at the top of Sideloadly, click Start, and enter your Apple ID details if prompted. This is completely safe, your account is only used to sign the application.
		6) If all goes well, you should be able to launch **Boom!** from your homescreen.