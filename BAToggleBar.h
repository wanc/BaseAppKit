/*
 Copyright 2011 Dmitry Stadnik. All rights reserved.
 
 Redistribution and use in source and binary forms, with or without modification, are
 permitted provided that the following conditions are met:
 
 1. Redistributions of source code must retain the above copyright notice, this list of
 conditions and the following disclaimer.
 
 2. Redistributions in binary form must reproduce the above copyright notice, this list
 of conditions and the following disclaimer in the documentation and/or other materials
 provided with the distribution.
 
 THIS SOFTWARE IS PROVIDED BY DMITRY STADNIK ``AS IS'' AND ANY EXPRESS OR IMPLIED
 WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL DMITRY STADNIK OR
 CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 
 The views and conclusions contained in the software and documentation are those of the
 authors and should not be interpreted as representing official policies, either expressed
 or implied, of Dmitry Stadnik.
*/

#import <UIKit/UIKit.h>
#import "BAToggleItem.h"

@class BAToggleBar;


@protocol BAToggleBarDelegate <NSObject>

- (void)toggleBar:(BAToggleBar *)toggleBar didSelectItem:(NSString *)item atIndex:(NSInteger)index;
@optional
- (UIView<BAToggleItem> *)toggleBar:(BAToggleBar *)toggleBar viewForItem:(NSString *)item atIndex:(NSInteger)index;
- (UIView *)toggleBarSeparatorView:(BAToggleBar *)toggleBar;

@end


@interface BAToggleBar : UIView <UIScrollViewDelegate> {
	BOOL _centered;
	UIScrollView *_scrollView;
	UIImageView *_leftTailView;
	UIImageView *_rightTailView;
	NSMutableArray *_itemViews; // [UIView<BAToggleItem>]
	NSMutableArray *_items; // [NSString]
	NSInteger _selectedItemIndex;
	UIColor *_itemTextColor;
	UIColor *_selectedItemTextColor;
	UIColor *_selectedItemBackgroundColor;
	id<BAToggleBarDelegate> _delegate;
}

@property(nonatomic, assign) BOOL centered;
@property(nonatomic, copy) NSArray *items;
@property(nonatomic, assign) NSInteger selectedItemIndex;
@property(nonatomic, retain) UIColor *itemTextColor;
@property(nonatomic, retain) UIColor *selectedItemTextColor;
@property(nonatomic, retain) UIColor *selectedItemBackgroundColor;
@property(nonatomic, assign) IBOutlet id<BAToggleBarDelegate> delegate;

- (void)setSelectedItemIndex:(NSInteger)selectedItemIndex revealingItem:(BOOL)revealingItem;

@end