//
//  ATCAuthVault.h
//  Authenticator
//
//  Created by Tong G. on 2/16/16.
//  Copyright © 2016 Tong Kuo. All rights reserved.
//

@class ATCAuthVaultItem;

// ATCAuthVault class
@interface ATCAuthVault : NSObject
    {
@protected
    WSCKeychain __strong* backingStore_;

    NSString __strong* UUID_;
    NSDate __strong* createdDate_;
    NSDate __strong* modifiedDate_;
    }

#pragma mark - Initializations

+ ( ATCAuthVault* ) emptyAuthVaultWithMasterPassphrase: ( NSString* )_MasterPassphrase error: ( NSError** )_Error;

#pragma mark - Meta Data

@property ( strong, readonly ) NSString* UUID;

@property ( strong, readonly ) NSDate* createdDate;
@property ( strong, readonly ) NSDate* modifiedDate;

#pragma mark - Creating and Managing Vault Items

- ( ATCAuthVaultItem* ) addVaultItemWithIssuerName: ( NSString* )_IssuerName accountName: ( NSString* )_AccountName secret: ( NSString* )_Secret error: ( NSError** )_Error;
- ( ATCAuthVaultItem* ) findVaultItemWithName: ( NSString* )_ItemName error: ( NSError** )_Error;
- ( void ) deleteVaultItem: ( ATCAuthVaultItem* )_VaultItem error: ( NSError** )_Error;

@end // ATCAuthVault class