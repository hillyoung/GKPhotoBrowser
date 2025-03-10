//
//  GKPhotoBrowser.h
//  GKPhotoBrowser
//
//  Created by QuintGao on 2017/10/20.
//  Copyright © 2017年 QuintGao. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "GKPhotoView.h"

#if __has_include(<GKPhotoBrowser/GKPhotoBrowser-Swift.h>)
#import <GKPhotoBrowser/GKPhotoBrowser-Swift.h>
#endif

#if __has_include(<GKPhotoBrowser/GKSDWebImageManager.h>)
#import <GKPhotoBrowser/GKSDWebImageManager.h>
#endif

#if __has_include(<GKPhotoBrowser/GKYYWebImageManager.h>)
#import <GKPhotoBrowser/GKYYWebImageManager.h>
#endif

#if __has_include(<GKPhotoBrowser/GKAVPlayerManager.h>)
#import <GKPhotoBrowser/GKAVPlayerManager.h>
#endif

#if __has_include(<GKPhotoBrowser/GKZFPlayerManager.h>)
#import <GKPhotoBrowser/GKZFPlayerManager.h>
#endif

#if __has_include(<GKPhotoBrowser/GKIJKPlayerManager.h>)
#import <GKPhotoBrowser/GKIJKPlayerManager.h>
#endif

#if __has_include(<GKPhotoBrowser/GKAFLivePhotoManager.h>)
#import <GKPhotoBrowser/GKAFLivePhotoManager.h>
#endif

#if __has_include(<GKPhotoBrowser/GKProgressView.h>)
#import <GKPhotoBrowser/GKProgressView.h>
#endif

NS_ASSUME_NONNULL_BEGIN

@class GKPhotoBrowser;

typedef void(^layoutBlock)(GKPhotoBrowser *photoBrowser, CGRect superFrame);

@protocol GKPhotoBrowserDelegate<NSObject>

@optional

// 滚动到一半时索引改变
- (void)photoBrowser:(GKPhotoBrowser *)browser didChangedIndex:(NSInteger)index;

// 选择photoView时回调
- (void)photoBrowser:(GKPhotoBrowser *)browser didSelectAtIndex:(NSInteger)index;

// 单击事件
- (void)photoBrowser:(GKPhotoBrowser *)browser singleTapWithIndex:(NSInteger)index;

// 双击事件
- (void)photoBrowser:(GKPhotoBrowser *)browser doubleTapWithIndex:(NSInteger)index;

// 长按事件
- (void)photoBrowser:(GKPhotoBrowser *)browser longPressWithIndex:(NSInteger)index;

// 旋转事件
- (void)photoBrowser:(GKPhotoBrowser *)browser onDeciceChangedWithIndex:(NSInteger)index isLandscape:(BOOL)isLandscape;

// 缩放事件
- (void)photoBrowser:(GKPhotoBrowser *)browser zoomEndedWithIndex:(NSInteger)index zoomScale:(CGFloat)scale;

// photoView复用回调
- (void)photoBrowser:(GKPhotoBrowser *)browser reuseAtIndex:(NSInteger)index photoView:(GKPhotoView *)photoView;

// 保存按钮点击事件
- (void)photoBrowser:(GKPhotoBrowser *)browser onSaveBtnClick:(NSInteger)index image:(UIImage *)image;

// 上下滑动消失
// 开始滑动时
- (void)photoBrowser:(GKPhotoBrowser *)browser panBeginWithIndex:(NSInteger)index;

// 结束滑动时 disappear：是否消失
- (void)photoBrowser:(GKPhotoBrowser *)browser panEndedWithIndex:(NSInteger)index willDisappear:(BOOL)disappear;

// 布局子视图
- (void)photoBrowser:(GKPhotoBrowser *)browser willLayoutSubViews:(NSInteger)index;

// browser完全消失回调
- (void)photoBrowser:(GKPhotoBrowser *)browser didDisappearAtIndex:(NSInteger)index;

// browser自定义加载方式时回调
- (void)photoBrowser:(GKPhotoBrowser *)browser loadImageAtIndex:(NSInteger)index progress:(float)progress isOriginImage:(BOOL)isOriginImage;

// browser加载失败自定义弹窗
- (void)photoBrowser:(GKPhotoBrowser *)browser loadFailedAtIndex:(NSInteger)index error:(NSError *)error;

// 自定义单个图片或视频的加载失败文字，优先级高于failureText
- (NSString *)photoBrowser:(GKPhotoBrowser *)browser failedTextAtIndex:(NSInteger)index;

// 自定义单个图片或视频的加载失败图片，优先级高于failureImage
- (UIImage *)photoBrowser:(GKPhotoBrowser *)browser failedImageAtIndex:(NSInteger)index;

// 视频相关
// 视频播放状态回调
- (void)photoBrowser:(GKPhotoBrowser *)browser videoStateChangeWithPhotoView:(GKPhotoView *)photoView status:(GKVideoPlayerStatus)status;

// 视频播放进度回调
- (void)photoBrowser:(GKPhotoBrowser *)browser videoTimeChangeWithPhotoView:(GKPhotoView *)photoView currentTime:(NSTimeInterval)currentTime totalTime:(NSTimeInterval)totalTime;

// 视频加载回调，用于自定义加载方式
// isStart: 是否开始加载  success：加载是否成功
- (void)photoBrowser:(GKPhotoBrowser *)browser videoLoadStart:(BOOL)isStart success:(BOOL)success;

// browser UIScrollViewDelegate
- (void)photoBrowser:(GKPhotoBrowser *)browser scrollViewWillBeginDragging:(UIScrollView *)scrollView;
- (void)photoBrowser:(GKPhotoBrowser *)browser scrollViewDidScroll:(UIScrollView *)scrollView;
- (void)photoBrowser:(GKPhotoBrowser *)browser scrollViewDidEndDecelerating:(UIScrollView *)scrollView;
- (void)photoBrowser:(GKPhotoBrowser *)browser scrollViewDidEndDragging:(UIScrollView *)scrollView willDecelerate:(BOOL)decelerate;
- (void)photoBrowser:(GKPhotoBrowser *)browser scrollViewDidEndScrollingAnimation:(UIScrollView *)scrollView;

@end

@interface GKPhotoBrowser : UIViewController
/** 底部容器 */
@property (nonatomic, strong, readonly) UIView        *containerView;
/** 底部内容试图 */
@property (nonatomic, strong, readonly) UIView        *contentView;
/** 滑动容器视图 */
@property (nonatomic, strong, readonly) UIScrollView  *photoScrollView;
/** 图片模型数组 */
@property (nonatomic, strong, readonly) NSArray       *photos;
/** 当前索引 */
@property (nonatomic, assign, readonly) NSInteger     currentIndex;
/** 当前显示的photoView */
@property (nonatomic, strong, readonly) GKPhotoView   *curPhotoView;
/** 当前的数据模型 */
@property (nonatomic, strong, readonly) GKPhoto       *curPhoto;
/** coverView数组 */
@property (nonatomic, strong, readonly) NSArray       *coverViews;
/** 是否是横屏 */
@property (nonatomic, assign, readonly) BOOL          isLandscape;
/** 当前设备的方向 */
@property (nonatomic, assign, readonly) UIDeviceOrientation currentOrientation;

/** 显示方式，默认GKPhotoBrowserShowStyleZoom */
@property (nonatomic, assign) GKPhotoBrowserShowStyle showStyle;
/** 隐藏方式，默认GKPhotoBrowserHideStyleZoom */
@property (nonatomic, assign) GKPhotoBrowserHideStyle hideStyle;
/** 图片加载方式，默认GKPhotoBrowserLoadStyleIndeterminate */
@property (nonatomic, assign) GKPhotoBrowserLoadStyle loadStyle;
/** 原图加载加载方式，默认GKPhotoBrowserLoadStyleIndeterminate */
@property (nonatomic, assign) GKPhotoBrowserLoadStyle originLoadStyle;
/** 图片加载失败显示方式，默认GKPhotoBrowserFailStyleOnlyText */
@property (nonatomic, assign) GKPhotoBrowserFailStyle failStyle;
/** 代理 */
@property (nonatomic, weak) id<GKPhotoBrowserDelegate> delegate;

/// 是否跟随系统旋转，默认是NO，如果设置为YES，isScreenRotateDisabled属性将失效
@property (nonatomic, assign) BOOL isFollowSystemRotation;

/// 是否禁止屏幕旋转监测
@property (nonatomic, assign) BOOL isScreenRotateDisabled;

/// 是否禁用默认单击事件
@property (nonatomic, assign) BOOL isSingleTapDisabled;

/// 是否禁用双击事件，默认NO
@property (nonatomic, assign) BOOL isDoubleTapDisabled;

/// 是否禁用双击放大缩小
@property (nonatomic, assign) BOOL isDoubleTapZoomDisabled;

/// 是否显示状态栏，默认NO：不显示状态栏
@property (nonatomic, assign) BOOL isStatusBarShow;

/// 状态栏样式，默认Light
@property (nonatomic, assign) UIStatusBarStyle statusBarStyle;

/// 滑动消失时是否隐藏原来的视图：默认YES
@property (nonatomic, assign) BOOL isHideSourceView;

/// 滑动切换图片时，是否恢复上（下）一张图片的缩放程度，默认是NO
/// 如果滑动超过一张，则恢复原状
@property (nonatomic, assign) BOOL isResumePhotoZoom;

/// 横屏时是否充满屏幕宽度，默认YES，为NO时图片自动填充屏幕
@property (nonatomic, assign) BOOL isFullWidthForLandScape;

/// 是否适配安全区域，默认NO，为YES时图片会自动适配iPhone X的安全区域
@property (nonatomic, assign) BOOL isAdaptiveSafeArea;

/// 是否启用滑动返回手势处理（当showStyle为GKPhotoBrowserShowStylePush时有效）
@property (nonatomic, assign) BOOL isPopGestureEnabled;

/// 是否隐藏countLabel，默认NO
@property (nonatomic, assign) BOOL hidesCountLabel;

/// 是否隐藏pageControl，默认NO
@property (nonatomic, assign) BOOL hidesPageControl;

/// 是否隐藏saveBtn，默认YES
@property (nonatomic, assign) BOOL hidesSavedBtn;

/// 默认图片高度
@property (nonatomic) CGFloat defaultImageHeight;
/// 默认最大缩放比例
@property (nonatomic, readonly) CGFloat defaultMaxZoomScale;
/// 图片最大放大倍数
@property (nonatomic, assign) CGFloat maxZoomScale;

/// 双击放大倍数，默认maxZoomScale，不能超过maxZoomScale
@property (nonatomic, assign) CGFloat doubleZoomScale;

/// 图片间距，默认10
@property (nonatomic, assign) CGFloat photoViewPadding;

/// 动画时间，默认0.3
@property (nonatomic, assign) NSTimeInterval animDuration;

/// 浏览器背景（默认黑色）
@property (nonatomic, strong) UIColor *bgColor;

/// 数量Label，默认显示，若要隐藏需设置hidesCountLabel为YES
@property (nonatomic, strong) UILabel *countLabel;

/// 页码，默认显示，若要隐藏需设置hidesPageControl为YES
@property (nonatomic, strong) UIPageControl *pageControl;

/// 保存按钮，默认隐藏
@property (nonatomic, strong) UIButton *saveBtn;

/// 加载失败时显示的文字或图片
@property (nonatomic, copy) NSString    *failureText;
@property (nonatomic, strong) UIImage   *failureImage;

/// 视频播放失败显示的文字或图片
@property (nonatomic, copy) NSString *videoFailureText;
@property (nonatomic, strong) UIImage *videoFailureImage;

/// 是否添加导航控制器，默认NO，添加后会默认隐藏导航栏
/// showStyle = GKPhotoBrowserShowStylePush时无效
@property (nonatomic, assign, getter=isAddNavigationController) BOOL addNavigationController;

/// 浏览器消失时是否清除缓存，默认NO
/// 如果设置为YES，则结束显示时会调用GKWebImageProtocol协议的clearMemory方法
@property (nonatomic, assign) BOOL isClearMemoryWhenDisappear;

/// 视图重用时是否清除对应url的缓存，默认NO
/// 如果设置为YES，则视图放入重用池时会调用GKWebImageProtocol协议的clearMemoryForURL:方法
@property (nonatomic, assign) BOOL isClearMemoryWhenViewReuse;

#pragma mark - 视频相关
/** 视频播放处理 */
@property (nonatomic, strong, readonly) id<GKVideoPlayerProtocol> player;
/** 视频进度试图 */
@property (nonatomic, weak, readonly, nullable) UIView *progressView;
/// 是否隐藏进度视频进度视图，默认NO，内容为视频时有效
@property (nonatomic, assign) BOOL hidesVideoSlider;
/** 视频加载方式，默认GKPhotoBrowserLoadStyleIndeterminate */
@property (nonatomic, assign) GKPhotoBrowserLoadStyle videoLoadStyle;
/** 视频播放失败显示方式，默认GKPhotoBrowserFailStyleOnlyText */
@property (nonatomic, assign) GKPhotoBrowserFailStyle videoFailStyle;
/// 视频暂停或停止时是否显示播放图标，默认YES
@property (nonatomic, assign) BOOL showPlayImage;
/// 视频暂停或停止时显示的播放图
@property (nonatomic, strong) UIImage *videoPlayImage;
/// 视频是否静音播放
@property (nonatomic, assign) BOOL videoMutedPlay;
/// 视频播放结束后是否自动重播，默认YES
@property (nonatomic, assign) BOOL isVideoReplay;
/// 拖拽消失时是否暂停播放，默认YES
@property (nonatomic, assign) BOOL isVideoPausedWhenDragged;
/// 左右滑动开始时是否暂停播放视频，默认NO
@property (nonatomic, assign) BOOL isVideoPausedWhenScrollBegan;

#pragma mark - livePhoto相关
/** livePhoto处理 */
@property (nonatomic, strong, readonly) id<GKLivePhotoProtocol> livePhoto;
/** livePhoto加载方式，默认GKPhotoBrowserLoadStyleDeterminateSector*/
@property (nonatomic, assign) GKPhotoBrowserLoadStyle liveLoadStyle;
/// 拖拽消失时是否暂停播放livePhoto，默认YES
@property (nonatomic, assign) BOOL isLivePhotoPausedWhenDragged;
/// 左右滑动开始时是否暂停播放livePhoto，默认NO
@property (nonatomic, assign) BOOL isLivePhotoPausedWhenScrollBegan;
/// livePhoto是否静音播放
@property (nonatomic, assign) BOOL livePhotoMutedPlay;
// 是否显示livePhoto标识，默认NO
@property (nonatomic, assign) BOOL isShowLivePhotoMark;
// 是否清理livePhoto缓存，默认YES
@property (nonatomic, assign) BOOL isClearMemoryForLivePhoto;

// 初始化方法
/// 创建图片浏览器
///   - photos: 包含GKPhoto对象的数组
///   - currentIndex: 当前的索引
+ (instancetype)photoBrowserWithPhotos:(NSArray<GKPhoto *> *)photos currentIndex:(NSInteger)currentIndex;

/// 创建图片浏览器
/// @param photos 包含GKPhoto对象的数组
/// @param currentIndex 当前的索引
- (instancetype)initWithPhotos:(NSArray<GKPhoto *> *)photos currentIndex:(NSInteger)currentIndex;

/// 自定义图片请求类
/// @param protocol 需实现GKWebImageProtocol协议
- (void)setupWebImageProtocol:(id<GKWebImageProtocol>)protocol;

/// 自定义视频播放处理类，需要视频播放时必须添加
/// @param protocol 需实现GKVideoPlayerProtocol协议
- (void)setupVideoPlayerProtocol:(id<GKVideoPlayerProtocol>)protocol;

/// 自定义livePhoto加载处理类
/// @param protocol 需实现GKLivePhotoProtocol协议
- (void)setupLivePhotoProtocol:(id<GKLivePhotoProtocol>)protocol;

/// 自定义视频播放进度条
/// @param protocol 需实现GKProgressViewProtocol协议
- (void)setupVideoProgressProtocol:(id<GKProgressViewProtocol>)protocol;

/**
 为浏览器添加自定义遮罩视图

 @param coverViews  视图数组
 @param layoutBlock 布局
 */
- (void)setupCoverViews:(NSArray *)coverViews layoutBlock:(layoutBlock)layoutBlock;

/**
 显示图片浏览器
 */
- (void)showFromVC:(UIViewController *)vc;

/// 隐藏图片浏览器
- (void)dismiss;

/// 选中指定位置的内容
- (void)selectedPhotoWithIndex:(NSInteger)index animated:(BOOL)animated;

/// 移除指定位置的内容
- (void)removePhotoAtIndex:(NSInteger)index;

/// 重置浏览器数据源
- (void)resetPhotoBrowserWithPhotos:(NSArray *)photos;

/// 重置某个索引对于的数据
- (void)resetPhotoBrowserWithPhoto:(GKPhoto *)photo index:(NSInteger)index;

/// 加载原图方法，外部调用
- (void)loadCurrentPhotoImage;

@end

// 内部方法，无需关心
@interface GKPhotoBrowser (Private)

// 更新布局
- (void)layoutSubviews;

// 浏览器第一次显示
- (void)browserFirstAppear;

// 移除旋转监听
- (void)removeRotationObserver;

@end

NS_ASSUME_NONNULL_END
