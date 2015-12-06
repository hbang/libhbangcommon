#import "HBListController.h"
#import <MessageUI/MFMailComposeViewController.h>

/**
 * The `HBAboutListController` class in `CepheiPrefs` provides a list controller
 * with functions that would typically be used on an "about" page. It includes
 * two class methods you can override to provide a developer website and
 * donation URL, and a class method to provide an email address so the user can
 * send the developer an email right from the tweak's settings.
 *
 * There is a sample of an HBAboutListController implemented in the Cephei demo
 * preferences. See the Cephei readme for details.
 *
 * ### Example Usage
 * 	<dict>
 * 		<key>action</key>
 * 		<string>hb_openWebsite</string>
 * 		<key>cell</key>
 * 		<string>PSButtonCell</string>
 * 		<key>cellClass</key>
 * 		<string>HBTintedTableCell</string>
 * 		<key>label</key>
 * 		<string>Visit Website</string>
 * 	</dict>
 * 	<dict>
 * 		<key>cell</key>
 * 		<string>PSGroupCell</string>
 * 		<key>footerText</key>
 * 		<string>Experiencing issues? Send us an email and we’ll help you.</string>
 * 	</dict>
 * 	<dict>
 * 		<key>cell</key>
 * 		<string>PSGroupCell</string>
 * 	</dict>
 * 	<dict>
 * 		<key>action</key>
 * 		<string>hb_sendSupportEmail</string>
 * 		<key>cell</key>
 * 		<string>PSButtonCell</string>
 * 		<key>cellClass</key>
 * 		<string>HBTintedTableCell</string>
 * 		<key>label</key>
 * 		<string>Email Support</string>
 * 	</dict>
 * 	<dict>
 * 		<key>cell</key>
 * 		<string>PSGroupCell</string>
 * 		<key>footerText</key>
 * 		<string>If you like this tweak, please consider a donation.</string>
 * 	</dict>
 * 	<dict>
 * 		<key>cell</key>
 * 		<string>PSGroupCell</string>
 * 	</dict>
 * 	<dict>
 * 		<key>action</key>
 * 		<string>hb_openDonate</string>
 * 		<key>cell</key>
 * 		<string>PSButtonCell</string>
 * 		<key>cellClass</key>
 * 		<string>HBTintedTableCell</string>
 * 		<key>label</key>
 * 		<string>Donate</string>
 * 	</dict>
 */

NS_ASSUME_NONNULL_BEGIN

@interface HBAboutListController : HBListController <MFMailComposeViewControllerDelegate>

/**
 * @name Constants
 */

/**
 * The website URL to open when tapping the "visit website" cell. Override this
 * method to return your own URL.
 *
 * @returns By default, https://www.hbang.ws/.
 */
+ (NSURL *)hb_websiteURL;

/**
 * The website URL to open when tapping the "donate" cell. Override this method
 * to return your own URL.
 *
 * @returns By default, https://www.hbang.ws/donate/.
 */
+ (NSURL *)hb_donateURL;

/**
 * The email address to use in the support email composer form. Override this
 * method to return an email address.
 *
 * If this method returns nil, the package’s author email address is used.
 *
 * @returns By default, nil.
 */
+ (nullable NSString *)hb_supportEmailAddress;

/**
 * The instructions to provide to the TechSupport framework, in addition to the
 * default ones provided by Cephei. For details and examples of support
 * instructions, refer to the TechSupport project’s GitHub repo:
 * https://github.com/ashikase/TechSupport/tree/master/Demo
 *
 * @returns By default, nil.
 * @see HBSupportController
 */
+ (nullable NSArray *)hb_supportInstructions;

/**
 * @name Preference Specifier Actions
 */

/**
 * Opens the user's browser to the URL specified by hb_websiteURL.
 *
 * Deprecated. It is encouraged to use an HBLinkTableCell instead.
 */
- (void)hb_openWebsite __attribute((deprecated("Use an HBLinkTableCell instead.")));

/**
 * Opens the user's browser to the URL specified by hb_donateURL.
 *
 * Deprecated. It is encouraged to use an HBLinkTableCell instead.
 */
- (void)hb_openDonate __attribute((deprecated("Use an HBLinkTableCell instead.")));

/**
 * Displays a support composer form.
 *
 * The hb_supportEmailAddress and hb_supportInstructions methods are used to
 * provide the appropriate parameters to `HBSupportController`.
 *
 * @see HBSupportController
 */
- (void)hb_sendSupportEmail;

@end

NS_ASSUME_NONNULL_END
